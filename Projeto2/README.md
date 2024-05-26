## Integrantes

- Gabriel Fuentes de Freitsa Yamashita - 10408876
- Matheus Tobias Mustaro -  10409259

# Projeto 2 - SO

## Sobre o projeto

O projeto consiste em resolver o problema do código apresentado, que no caso é a condição de corrida no código, em que vários subprocessos tentam executar a função transferencia ao mesmo tempo, por conta dos saldos serem compartilhados entre os subprocessos.

Alteramos o código inicial para que o problema seja corrigido utilizando a biblioteca `pthread`, para manipular threads e usar mutexes, utilizados para garantir que somente uma thread por vez possa acessar e modificar as contas, evitando conflitos e inconsistências nos saldos, além disso no código modificado a direção de cada transação é feita de forma aleatória, podendo ser tanto de from para to como o contrário.

## Testes

Os resultados obtidos estão nos prints abaixo.

# Print com 20 transações e valor de transferência 10

(saldo from = 100, saldo to = 100)

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/9a2479f6-2613-4e8b-9c68-3054c454a01f)

# Print com 30 transações e valor de transferência 20

(saldo from = 100, saldo to = 100)

![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/77130ee1-982a-4bd2-8596-d8929d9d91bc)
![image](https://github.com/Gabriel-Fuentes-de-Freitas-Yamashita/Sistemas-OP/assets/161405047/f87afb03-9471-49dc-aa6a-48f343968332)
