#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <unistd.h>

// 64kB de pilha
#define FIBER_STACK (1024*64)

// Estrutura para armazenar dados compartilhados
struct ThreadData {
  volatile sig_atomic_t ready;
  volatile int numero_compartilhado;
};

// Função que a thread irá executar
int threadFunction(void* argumento) {
  struct ThreadData *data = (struct ThreadData *)argumento;

  printf("Thread filho aguardando sinal...\n");
  while (!data->ready); // Espera pelo sinal da thread principal
  printf("Thread filho recebeu sinal!\n");

  // Realiza a operação matemática (dobrar o número)
  int resultado = data->numero_compartilhado * 2;

  // Envia o resultado de volta para a thread principal
  printf("Resultado da operação matemática: %d\n", resultado);

  printf("Thread filho saindo\n");
  return 0;
}

int main() {
  void* pilha;
  pid_t pid;

  // Aloca a pilha
  pilha = malloc(FIBER_STACK);
  if (pilha == 0) {
    perror("malloc: não foi possível alocar a pilha");
    exit(1);
  }

  printf("Criando thread filho\n");

  // Configura dados compartilhados
  struct ThreadData data;
  data.ready = 0;
  data.numero_compartilhado = 0;

  // Chama a chamada de sistema clone para criar a thread filho
  pid = clone(&threadFunction, (char*) pilha + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &data);
  if (pid == -1) {
    perror("clone");
    exit(2);
  }

  // Define o número compartilhado para a operação matemática
  data.numero_compartilhado = 10;
  printf("O número para a operação: %d\n", data.numero_compartilhado);

  // Aguarda um curto período de tempo
  sleep(1);

  // Envia um sinal para a thread filho
  printf("Enviando sinal para a thread filho\n");
  data.ready = 1;

  // Espera a thread filho sair
  pid = waitpid(pid, 0, 0);
  if (pid == -1) {
    perror("waitpid");
    exit(3);
  }

  // Libera a pilha
  free(pilha);
  printf("Thread filho retornou e pilha liberada.\n");
  return 0;
}
