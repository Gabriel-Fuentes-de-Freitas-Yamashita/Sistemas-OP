Lab2 ex1 

Como compilar o programa na plataforma disponibilizada;


Primeiramente eu criei um diretorio chamado meus_scripts usando mkdir meus_scripts, após isso criei um arquivo chamado pef_fork_teste.c usando vi pef_fork_teste.c, dai eu já fui redirecionado para a parte de edição do arquivo na aba de -- INSERT -- escrevi o codigo que vi em uma video aula no youtube, logo após isso dei ESC e :wq para salvar a edição do arquivo,
em seguida repeti o processo da criação do arquivo, com o objetivo de fazer o meu proprio codigo que atendesse a proposta do ex1, e o nome do arquivo ficou pef_fork.c


Como executar o programa;

Para executar o código, fiz update da lista de pacotes disponíveis e os pacotes já instalados usando sudo yum update -y e instalei o compilador C mais comum, o GCC (GNU Compiler Collection) por meio do comando: sudo yum install gcc

com isso executei os programas por meio desses comandos: 
gcc -o pef_fork_teste pef_fork_teste.c 
./pef_fork_teste

gcc -o pef_fork pef_fork.c
./pef_fork



Para comprovar que os resultados propostos foram alcançados, seguem os prints relacionados ao terminal;

![image](C:\Users\bielf\Pictures\Saved Pictures\print.png)

