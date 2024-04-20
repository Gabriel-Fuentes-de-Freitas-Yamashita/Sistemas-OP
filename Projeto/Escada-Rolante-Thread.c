#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int escadaRolante(int* t, int* d, int n) {
  int tempoAtual = t[0], distanciaAtual = d[0];
  int mainIndice = 0;
  int auxIndice = 0;
  int chegadaEsperada; 
  int tempoPendente[10000], direcPendente[10000], passageirosRestantes = n, ultimoInstante = 0, direcao = -1, instante = 0;
  bool pending = false;

  while (passageirosRestantes > 0) {
    if (pending && (t[mainIndice] > chegadaEsperada || mainIndice >= n)) {
    tempoAtual = tempoPendente[0];
    distanciaAtual = direcPendente[0];
    instante += 10;
    direcao = distanciaAtual;
    chegadaEsperada = instante + 10;
    passageirosRestantes--;
    pending = false;
    } else {
    tempoAtual = t[mainIndice];
    distanciaAtual = d[mainIndice];

      if (direcao == -1) {
        instante = tempoAtual < instante ? instante : tempoAtual;
        direcao = distanciaAtual;
        chegadaEsperada = tempoAtual + 10;
        mainIndice++;
        passageirosRestantes--;
      } else if (direcao == distanciaAtual) {
        instante = tempoAtual;
        chegadaEsperada = tempoAtual + 10;
        mainIndice++;
        passageirosRestantes--;
      } else {
        if (t[mainIndice + 1] - t[mainIndice] > t[mainIndice - 1]) {
          instante = chegadaEsperada;
          direcao = -1;
        } else if (t[mainIndice + 1] <= chegadaEsperada) {
          tempoPendente[0] = t[mainIndice]; 
          direcPendente[0] = d[mainIndice];
          pending = true;
          mainIndice++;
        }
      }
    }
  }

  instante += 10;
  ultimoInstante = instante;

  return ultimoInstante;
}

void lerData(char* caminhoArquivo, int* t, int* d, int* n) {
  FILE* file = fopen(caminhoArquivo, "r");
  if (file == NULL) {
    printf("Ocorreu um erro ao abrir o arquivo %s.\n", caminhoArquivo);
    exit(1);
  }

  fscanf(file, "%d", n);
  for (int i = 0; i < *n; i++) {
    fscanf(file, "%d %d", &t[i], &d[i]);
  }
  fclose(file);
}

void* threadFunc(void* arg) {
  int* arr = (int*)arg;
  int ultimoInstante = escadaRolante(arr, (arr+10000), *(arr+20000));
  printf("O ultimo instante em que a escada para e %d\n", ultimoInstante);
  pthread_exit(0);
}

int main() {
  int t[10000], d[10000], n;
  char caminhoArquivo[100];

  printf("Digite o diretorio e o arquivo que deseja usar: ");
  scanf("%s", caminhoArquivo);

  lerData(caminhoArquivo, t, d, &n);

  int arr[20001];
  for(int i = 0; i < 10000; i++) {
    arr[i] = t[i];
    arr[i+10000] = d[i];
  }
  arr[20000] = n;

  pthread_t thread;
  if(pthread_create(&thread, NULL, threadFunc, (void*)arr)) {
    fprintf(stderr, "Erro ao criar a thread.\n");
    return 1;
  }

  if(pthread_join(thread, NULL)) {
    fprintf(stderr, "Erro ao juntar a thread.\n");
    return 2;
  }

  return 0;
}


