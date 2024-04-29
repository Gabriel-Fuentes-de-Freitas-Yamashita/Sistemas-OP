LAB 04

Integrantes:

Matheus Tobias Mustaro
RA:10409259

Gabriel Fuentes de Freitas Yamashita
RA: 10408876

Exercicio:
Construa uma solução utilizando pthreads para resolver o problema da multiplicação matriz-vetor.

Codigo:
Definimos as linhas e colunas como tamanho 3x3, e os vetores da matriz são:
[ 1 2 3 ]
[ 4 5 6 ]
[ 7 8 9 ]

A função "Pth_mat_vect", realiza o calculo da multiplicação dos vetores da matriz. Já na main, nós criamos as threads, e as armazenamos em um vetor, o mais eficiente é sempre utilizar uma thread por linha. Então enviamos cada thread diretamente a função do enunciado. As threads retornarão e aguardarão no join até que todas concluam, depois as threads são liberadas e o resuldado é exibido.


 









