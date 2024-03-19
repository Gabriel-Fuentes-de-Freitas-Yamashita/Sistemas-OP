EXERCICIO 03

Integrantes:

Matheus Tobias Mustaro

RA:10409259

Gabriel Fuentes de Freitas Yamashita

RA: 10408876

EXERCÍCIO: Incremente o exemplo acima para representar a troca de informações de contexto
entre a thread e o processo pai.

IMAGEM DO CONSOLE

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/9d58427e-cddb-47e8-a341-54a0da2c502f)


De acordo com o Resultado do Console acima, podemos perceber que primeiramente, a thread filho é criada, a parte disso, mostramos qual será o número base de nossa operação (x * 2), seguinte a isso, o thread filho espera o sinal do pai, no caso o resultado da operação, chegar para ele, a thread filho exibe o resultado. 


COMPLEMENTO:

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/162312537/ebb7a57b-db60-4289-ae58-7b0d7d206c89)

Para provarmos que existe compartilhamento do endereço de memória, implementamos no código um print com o endereço das thread principal e filho, assim podemos ver que o endereço é o mesmo.







