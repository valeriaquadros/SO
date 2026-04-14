/**
 * Programa que cria duas threads: uma que quer escrever AA em buffer
 * e outra que quer escrever Bb.
 * Use semáforos para garantir que 'A' seja impresso antes de 'b' e que 'B' seja
 * impresso antes de 'a'. A ordem de A e B não importa.
 *
 * Para compilar:
 * gcc -o ordena_atributo ordena_atributo.c -pthread
 *
 * Para executar:
 * ./ordena_atributo
 */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

void *A(void *param);
void *B(void *param);

char buffer[5] = "\0";

// XXX declare aqui o(s) semáforo(s) necessário(s)

int main(int argc, char *argv[]) {
	pthread_t tids[2];

	// XXX inicialize o(s) semáforo(s)

	pthread_create(&tids[0], NULL, A, NULL);
	pthread_create(&tids[1], NULL, B, NULL);
	
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	
	printf("Valor de impressão: %s\n", buffer);

	return 0;
}

void *A(void *param) {
	strcat(buffer, "A");
	strcat(buffer, "a");
}

void *B(void *param) {
	strcat(buffer, "B");
	strcat(buffer, "b");
}
