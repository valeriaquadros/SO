/**
 * Programa que cria diversas threads. Cada thread executa uma função que 
 * imprime o seu identificador e o valor de algumas variáveis. Qual o valor 
 * dessas variáveis? Quais delas podem ser alteradas pelas threads? 
 * 
 * Para compilar: 
 * gcc thread_var_compart thread_var_compart.c 
 * Exemplo de execução:
 * ./thread_var_compart
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid); /* função que será executada pela thread */
int var_global = -1;

int main(int argc, char *argv[])
{
	pthread_t threads[NUMBER_OF_THREADS]; /* identificadores das threads */
	int status, i;

	for(i = 0; i < NUMBER_OF_THREADS; i++) {
		printf("Criando thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *)(intptr_t) i);

		if(status != 0) {
			printf("Ops, pthread_create retornou erro %d\n", status);
			exit(-1);
		}
	}

	pthread_exit(0);
	
	return 0;
}

/**
 * A thread inicia a execução nessa função
 */
void *print_hello_world(void *tid) 
{
    int var_local = (intptr_t) tid;
		
	if((intptr_t)tid == 3) { // terceira thread a ser criada altera o valor de var_global
	    var_global = 3;
	}
	
	/* Imprime o identificador da thread e sai. */
	printf("Olá Mundo! Saudações da thread %ld. O valor de var_global eh: %d. O valor da var_local eh: %d\n", (intptr_t)tid, var_global, var_local);
	
	pthread_exit((void*) 0);
}
