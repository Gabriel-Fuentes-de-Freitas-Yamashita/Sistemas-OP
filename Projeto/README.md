# Projeto - SO

## Sobre o projeto

O projeto consiste em criar um código para uma escada rolante dupla, que sobe e desce, e sendo necessário seguir algumas condições impostas no enunciado do problema, o que foi feito no código e descrito e mostrado através de imagens nos próximos itens. 

## Integrantes

- Gabriel Fuentes de  Freitas Yamashita -
- Matheus Tobias Mustaro - 

## Problema

Considere o problema da escada rolante em anexo. Implemente uma solução utilizando threads e outra utilizando processos e responda às seguintes perguntas:

## 1. Qual a estratégia que você utilizou para evitar que duas pessoas acessem a escada rolante ao mesmo tempo em cada abordagem?


- A estratégia principal envolve priorizar o acesso de passageiros que estão indo na mesma direção em que a escada está se movendo. Se houver um conflito de acesso, é dada prioridade ao passageiro que chegará mais cedo, enquanto os outros são colocados em espera até que a escada esteja livre para eles.

  
- Essa estratégia é implementada tanto na versão com processo filho quanto na versão com thread, garantindo que a lógica para evitar acessos simultâneos seja aplicada de maneira consistente.
O uso de processos (fork()) cria uma cópia exata do processo pai, que executa a função escadaRolante para calcular o último instante em que a escada para.


- O uso de threads (pthread_create) permite executar a função escadaRolante em uma thread separada dentro do mesmo processo. Isso é útil quando não há necessidade de isolamento completo entre as execuções, e a comunicação entre elas pode ser feita de forma eficiente, como neste caso, onde compartilhamos os mesmos dados de entrada (t, d, n) entre a thread pai e a thread filha.

## 2. Como garantir que somente uma das direções está ativa de cada vez em cada uma das abordagens?


- adicionamos uma variável global para controlar a direção da escada rolante, e antes de permitir que um passageiro acesse a escada, verificaremos se a direção solicitada pelo passageiro é a mesma que a direção atual da escada. Se não for, atualizaremos a direção para a direção solicitada pelo passageiro.

  
- Abordagem com Processos:
Variável Global de Controle de Direção: Uma variável global direcao_escada é utilizada para controlar a direção da escada.
Verificação e Atualização da Direção: Antes do acesso de um passageiro à escada, verifica-se se a direção solicitada é diferente da atual. Se sim, a direção é atualizada.
Exclusão Mútua com Processos Separados: Como os processos têm espaços de endereçamento separados, não é necessária uma sincronização explícita para garantir a exclusão mútua.


- Abordagem com Threads:
Variável Global de Controle de Direção: A mesma variável global direcao_escada é utilizada para controlar a direção da escada.
Exclusão Mútua com Mutex: Um mutex é utilizado para garantir a exclusão mútua ao acessar e atualizar a variável global compartilhada entre as threads.


- Comparação:
Ambas as abordagens compartilham o mesmo mecanismo de controle da direção da escada, mas diferem na necessidade de sincronização explícita:

A abordagem com processos não requer sincronização explícita devido ao espaço de endereçamento separado.
A abordagem com threads utiliza um mutex para garantir a exclusão mútua devido ao compartilhamento de recursos.


## 3. Discorra sobre as diferenças entre as implementações utilizando threads e processos e diga qual foi mais eficiente na solução do problema, justificando sua resposta.
-Diferenças entre as Implementações:


- Threads:


Threads compartilham o mesmo espaço de endereçamento, o que facilita a comunicação e o compartilhamento de dados entre elas.
As threads dentro de um processo têm um overhead menor em termos de criação e gerenciamento, pois não requerem a duplicação do espaço de endereçamento do processo pai.
As threads podem ser mais eficientes em termos de desempenho, pois a comunicação entre elas é mais direta e não envolve troca de mensagens entre processos separados.


- Processos:


Processos possuem espaços de endereçamento separados, o que significa que não compartilham dados automaticamente entre si. A comunicação entre processos geralmente requer mecanismos de IPC (Inter-Process Communication), como pipes, filas de mensagens ou memória compartilhada.
Criar um novo processo envolve um overhead maior em termos de recursos do sistema, pois requer a duplicação do espaço de endereçamento do processo pai.
Processos oferecem um maior nível de isolamento entre as unidades de execução, o que pode ser vantajoso em certos cenários onde é necessário evitar interferências indesejadas entre diferentes partes do código.


- Em Suma:


A implementação utilizando threads é mais eficiente na solução do problema da escada rolante devido ao compartilhamento direto de recursos, menor overhead de recursos e melhor desempenho em tarefas que envolvem comunicação frequente e compartilhamento de dados. Isso ocorre porque as threads compartilham o mesmo espaço de endereçamento, simplificando a comunicação e sincronização entre unidades de execução. Além disso, criar e gerenciar threads dentro de um processo é mais leve em termos de recursos do sistema do que criar processos separados.


## Teste

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/3a47709c-d69e-4acf-8c4c-acc35bae0a0b)

- Como é possivel perceber a entrada de num 10 carrega infinitamente e n conseguimos resolver este problema.

