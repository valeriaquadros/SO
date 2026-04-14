#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

FILE *fp; // variável global

void *thread_func(void *arg) {
    printf("Thread: endereço da variável fp = %p, valor do ponteiro = %p\n",
           (void*)&fp, (void*)fp);
    fprintf(fp, "Thread escreve.\n");
    pthread_exit(NULL);
}

int main() {
    pid_t pid;
    pthread_t thread;

    fp = fopen("teste.txt", "w");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    printf("Pai: endereço da variável fp = %p, valor do ponteiro = %p\n",
           (void*)&fp, (void*)fp);
    fprintf(fp, "Pai escreve.\n");

    pid = fork();

    if (pid == 0) { // filho
        printf("Filho: endereço da variável fp = %p, valor do ponteiro = %p\n",
               (void*)&fp, (void*)fp);
        fprintf(fp, "Filho escreve.\n");
        fclose(fp);
        exit(0);
    } else { // pai
        pthread_create(&thread, NULL, thread_func, NULL);
        pthread_join(thread, NULL);
        fclose(fp);
    }

    return 0;
}

