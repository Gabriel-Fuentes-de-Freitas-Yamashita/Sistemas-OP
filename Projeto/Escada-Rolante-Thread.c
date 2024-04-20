#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_DATA_SIZE 10000
#define MAX_FILENAME_LENGTH 100

int direcao_escada = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototypes
void lerData(const char* caminhoArquivo, int* t, int* d, int* n);
int escadaRolante(int* t, int* d, int n);
void* threadFunc(void* arg);

void lerData(const char* caminhoArquivo, int* t, int* d, int* n) {
    FILE* file = fopen(caminhoArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", caminhoArquivo);
        exit(1);
    }

    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %d", &t[i], &d[i]);
    }
    fclose(file);
}

int escadaRolante(int* t, int* d, int n) {
    int tempoAtual = t[0], distanciaAtual = d[0];
    int mainIndice = 0;
    int auxIndice = 0;
    int chegadaEsperada; 
    int tempoPendente[MAX_DATA_SIZE], direcPendente[MAX_DATA_SIZE], passageirosRestantes = n, ultimoInstante = 0, direcao = -1, instante = 0;
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

void* threadFunc(void* arg) {
    int* arr = (int*)arg;
    int ultimoInstante = escadaRolante(arr, arr + MAX_DATA_SIZE, arr[MAX_DATA_SIZE * 2]);
    printf("O ultimo instante em que a escada para e %d\n", ultimoInstante);
    pthread_exit(NULL);
}

int main() {
    int t[MAX_DATA_SIZE], d[MAX_DATA_SIZE], n;
    char caminhoArquivo[MAX_FILENAME_LENGTH];

    printf("Digite o diretorio e o arquivo que deseja usar: ");
    scanf("%s", caminhoArquivo);

    lerData(caminhoArquivo, t, d, &n);

    int arr[MAX_DATA_SIZE * 2 + 1];
    for (int i = 0; i < MAX_DATA_SIZE; i++) {
        arr[i] = t[i];
        arr[i + MAX_DATA_SIZE] = d[i];
    }
    arr[MAX_DATA_SIZE * 2] = n;

    pthread_t thread;
    if (pthread_create(&thread, NULL, threadFunc, (void*)arr)) {
        fprintf(stderr, "Erro ao criar a thread.\n");
        return 1;
    }

    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Erro ao juntar a thread.\n");
        return 2;
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
