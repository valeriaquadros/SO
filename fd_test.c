/**
 * Processo pai tem um arquivo aberto e cria uma thread filha e um processo filho. 
 * Qual(is) processo(s) tem acesso ao arquivo aberto? Por que?
 * Para compilar: 
 * gcc -o fd_test fd_test.c
 * Exemplo de execução:
 * ./fd_test
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 10000

FILE *fp;

void *foo(void *param); /* função que será executada pela thread */

// Main para a criação de processos.
int main(int argc, char *argv[])
{
	int childPid, n;
	pthread_t thread;
	
	fp = fopen("teste.txt", "w");
	
	if(fp != NULL) {
	    printf("Arquivo aberto com sucesso no processo pai.\n");
	    n = fwrite("Pai.\n", 1, 5, fp);
	    printf("Pai escreveu %d caracteres no arquivo.\n", n);
	}
	else {
	    printf("Erro ao abrir arquivo!\n");
	}
	
	childPid = fork();

	if(childPid == 0) {
	    n = fwrite("Filho.\n", 1, 7, fp);
	    printf("Filho escreveu %d caracteres no arquivo.\n", n);
	}
    else {
        pthread_create(&thread, NULL, foo, NULL);
        pthread_join(thread, NULL);
    }
		
	return 0;
}

/**
 * A thread inicia a execução nessa função
 */
void *foo(void *param) 
{
    int n;
    
    n = fwrite("Thread filha.\n", 1, 14, fp);
    printf("Thread filha escreveu %d caracteres no arquivo.\n", n);

	pthread_exit(NULL);
}
