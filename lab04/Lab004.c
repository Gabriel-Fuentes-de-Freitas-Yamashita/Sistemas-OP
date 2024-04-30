/*Integrantes:
Matheus Tobias Mustaro
RA:10409259

Gabriel Fuentes de Freitas Yamashita
RA: 10408876
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define linhas 3
#define colunas 3

// Definindo matrizes e vetores globais para que possam ser acessados por todas as threads e dentro da função
// O vetor de resultado "y" é declarado globalmente para que cada thread possa acessá-lo diretamente, evitando
// a necessidade de juntar os resultados de todas as threads posteriormente.
double A[linhas][colunas];  // Matriz de entrada
double x[colunas];          // Vetor de entrada
double y[linhas];           // Vetor de resultado

// Função executada por cada thread
void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = linhas / linhas;          // Determina quantas linhas cada thread processará
    int my_first_row = my_rank * local_m;   // Primeira linha a ser processada pela thread
    int my_last_row = (my_rank + 1) * local_m - 1;  // Última linha a ser processada pela thread

    // Cada thread calcula a multiplicação da matriz pelo vetor para as linhas atribuídas a ela
    for (i = my_first_row; i <= my_last_row; i++) {
        for (j = 0; j < colunas; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main() {
    // Preenchendo a matriz A e o vetor x
    int i, j = 0;
    double k = 0;
    // A matriz A é preenchida com valores sequenciais a partir de 1, percorrendo cada linha e coluna
    // O vetor x é preenchido com valores sequenciais a partir de 1
    // Assim, o problema será calculado para o vetor [1, 2, 3] e a matriz:
    // [[1, 2, 3]
    //  [4, 5, 6]
    //  [7, 8, 9]]

    printf("Matriz A:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            k++;
            A[i][j] = k;
            printf("%.0f ", A[i][j]);
        }
      printf("\n");
    }

    k = 0;
    printf("\nVetor x:\n");
    for (i = 0; i < colunas ; i++) {
        k++;
        x[i] = k;
        printf("%.0f ", x[i]);
    }
    printf("\n");
    
    // Criando threads para calcular o produto da matriz pelo vetor
    pthread_t* thread_handles;
    thread_handles = malloc(linhas * sizeof(pthread_t));

    // Cada thread será responsável pelo cálculo das linhas da matriz
    // O número de threads é igual ao número de linhas da matriz
    for (long thread = 0; thread < linhas; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    // Aguardando o término de todas as threads
    for (long thread = 0; thread < linhas; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    // Liberando a memória alocada para as threads
    free(thread_handles);

    // Exibindo o vetor resultado
    printf("\nResultado: [ ");
    for (i = 0; i < linhas ; i++) {
            printf("%f ", y[i]);
    }
    printf("]");
    return 0;
}
