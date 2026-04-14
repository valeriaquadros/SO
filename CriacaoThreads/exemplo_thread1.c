/**
 * Programa que cria diversas threads. Cada thread executa uma função que 
 * simplesmente imprime o seu identificador.
 *
 * Qual é a sequência de impressões observada? Essa sequência muda a cada 
 * execução? Por que?
 * 
 * Para compilar: 
 * gcc -o exemplo_thread1 exemplo_thread1.c
 * Exemplo de execução:
 * ./exemplo_thread1
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid); /* função que será executada pela thread */

int main(int argc, char *argv[])
{
	pthread_t threads[NUMBER_OF_THREADS]; /* identificadores das threads */
	int status, i;

	for(i = 0; i < NUMBER_OF_THREADS; i++) {
		printf("Criando thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *)(intptr_t)i);

		if(status != 0) {
			printf("Ops, pthread_create retornou erro %d\n", status);
			exit(-1);
		}
	}
	
	return 0;
}

/**
 * A thread inicia a execução nessa função
 */
void *print_hello_world(void *tid) 
{
	/* Imprime o identificador da thread e sai. */
	printf("Olá Mundo! Saudações da thread %ld\n", (intptr_t)tid);
	pthread_exit(NULL); // Podemos retirar essa chamada? Para que ela serve?
}
