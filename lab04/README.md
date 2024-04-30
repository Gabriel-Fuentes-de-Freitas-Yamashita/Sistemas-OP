# LAB 04

## Integrantes:

Matheus Tobias Mustaro

RA:10409259

Gabriel Fuentes de Freitas Yamashita

RA: 10408876


## Exercicio:

Construa uma solução utilizando pthreads para resolver o problema da multiplicação matriz-vetor.

## Compilação

- Para compilar o código, você pode usar o seguinte comando:

gcc -o matriz_vetor matriz_vetor.c -lpthread

## Execução

Para executar o programa, utilize o seguinte comando:

./matriz_vetor

## Principais Funções

### Pth_mat_vect()

- Esta função é executada por cada thread e é responsável por calcular a multiplicação da matriz pelo vetor para um conjunto de linhas atribuídas àquela thread. Ela recebe o índice da thread como argumento.

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/04fe2857-108a-4bff-b7fe-09591eb8797a)

### Main

- A função principal do programa. Ela preenche a matriz e o vetor, cria e executa as threads e imprime o vetor resultado.
 
![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/70164a07-a2e9-438e-adf0-672fb10a5c1c)

## Calculos Envolvidos

- A matriz de entrada A é uma matriz 3x3:

1 2 3


4 5 6


7 8 9

- O vetor de entrada x é um vetor coluna com 3 elementos:

1 2 3

- O resultado da multiplicação da matriz pelo vetor é calculado como segue:

y[0] = A[0][0]*x[0] + A[0][1]*x[1] + A[0][2]*x[2] = 1*1 + 2*2 + 3*3 = 14


y[1] = A[1][0]*x[0] + A[1][1]*x[1] + A[1][2]*x[2] = 4*1 + 5*2 + 6*3 = 32


y[2] = A[2][0]*x[0] + A[2][1]*x[1] + A[2][2]*x[2] = 7*1 + 8*2 + 9*3 = 50

## Exemplo de Saida

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/f417258f-440e-49c7-be93-4aa6003ee9f7)

