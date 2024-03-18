//Minha Versão

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) { // Processo filho
        printf("\n Processo filho: \n");
	printf("Oi pai!\n");
        printf("Saindo do processo filho\n");
        exit(0);

    } else { // Processo pai
        printf(" PID do filho: %d\n Processo pai:\n " , pid);
	printf("Oi filho!\n");
        printf("Saindo do processo pai\n");
    }

    return 0;
}
