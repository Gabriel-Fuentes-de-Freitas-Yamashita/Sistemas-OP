#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

// Variável global para controlar a direção da escada
int direcao_escada = -1; // Inicialmente, a escada está parada

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

            // Verificar e atualizar a direção da escada
            if (direcao_escada != distanciaAtual) {
                printf("A direcao da escada mudou para %s.\n", (distanciaAtual == 0 ? "baixo" : "cima"));
                direcao_escada = distanciaAtual;
            }

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

int main() {
  int t[10000], d[10000], n;
  char caminhoArquivo[100];

  printf("Digite o diretorio e o arquivo que deseja usar: ");
  scanf("%s", caminhoArquivo);

  lerData(caminhoArquivo, t, d, &n);

  pid_t pid = fork();  // Cria um novo processo

  if (pid < 0) {
    printf("Erro ao criar o processo.\n");
    return 1;
  }

  if (pid == 0) {  // Este bloco será executado pelo processo filho
    int ultimoInstante = escadaRolante(t, d, n);
    printf("O ultimo instante em que a escada para e %d\n", ultimoInstante);
    exit(0);  // Termina o processo filho
  } else {  // Este bloco será executado pelo processo pai
    wait(NULL);  // Espera o processo filho terminar

  }

  return 0;
}
