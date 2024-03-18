//https://www.youtube.com/watch?v=2oMd1yCZ3kE - video de referencia /Processos e fork

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int i;

    pid = fork();

    if (pid == 0) { // Processo filho
        printf("Processo filho\n");
        scanf("%d", &i);
        printf("Saindo do processo filho\n");
        exit(0);
    } else { // Processo pai
        printf("Processo pai. PID do filho: %d\n", pid);
        scanf("%d", &i);
        printf("Saindo do processo pai\n");
    }

    return 0;
}

