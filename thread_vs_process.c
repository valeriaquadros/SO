/**
 * Mede o tempo necessário para criar threads e o tempo para criar processos.
 * Qual dos dois tipos de criação é mais demorado? Por que?
 * Para compilar: 
 * gcc -o thread_vs_process thread_vs_process.c
 * Exemplo de execução:
 * ./thread_vs_process
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 10000

void *foo(void *param); /* função que será executada pela thread */

// Main para criação de threads.
int main(int argc, char *argv[])
{
	int status, i;
	struct timeval time1, time2;
	long elapsedTime;
	
	pthread_t threads[NUMBER_OF_THREADS]; // identificadores das threads 
	
	if (argc != 1) {
		fprintf(stderr,"Uso: ./thread_vs_process\n");
		// retorna indicando erro: exit(1);
		return -1;
	}

	
	gettimeofday(&time1, NULL);
	for(i = 0; i < NUMBER_OF_THREADS; i++) {
		status = pthread_create(&threads[i], NULL, foo, NULL);

		if(status != 0) {
			printf("Ops, pthread_create retornou erro %d\n", status);
			exit(-1);
		}
	}
	gettimeofday(&time2, NULL);

	elapsedTime = (time2.tv_sec-time1.tv_sec)*1000000 + time2.tv_usec-time1.tv_usec;	

	printf("Tempo para criação de %d threads: %lu microssegundos.\n", NUMBER_OF_THREADS, elapsedTime);
	
	return 0;
}

// Main para a criação de processos.
/*int main(int argc, char *argv[])
{
	int i, childPid;
	struct timeval time1, time2;
	long elapsedTime;
	
	if (argc != 1) {
		fprintf(stderr,"Uso: ./thread_vs_process\n");
		// retorna indicando erro: exit(1);
		return -1;
	}

	gettimeofday(&time1, NULL);
	for(i = 0; i < NUMBER_OF_THREADS; i++) {
		childPid = fork();

		if(childPid == 0) {
			exit(0);
		}

		if(childPid < 0) {
			printf("Ops, fork retornou erro %d\n", childPid);
			exit(-1);
		}
	}
	gettimeofday(&time2, NULL);

	elapsedTime = (time2.tv_sec-time1.tv_sec)*1000000 + time2.tv_usec-time1.tv_usec;	

	printf("Tempo para criação de %d processos: %lu microssegundos.\n", NUMBER_OF_THREADS, elapsedTime);
	
	return 0;
}*/

/**
 * A thread inicia a execução nessa função
 */
void *foo(void *param) 
{
	pthread_exit(NULL);
}
