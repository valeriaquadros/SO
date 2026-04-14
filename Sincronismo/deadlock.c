/**
 * Programa que cria duas threads: uma que quer escrever em buffer (produtora)
 * e outra que quer ler desse mesmo buffer (consumidora).
 *
 * Para compilar:
 * gcc -o deadlock deadlock.c -pthread
 *
 * Para executar:
 * ./deadlock
 */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int buffer[1];
void *produtora(void *param);
void *consumidora(void *param);

sem_t mutex;
sem_t vazio;
sem_t cheio;

int main(int argc, char *argv[]) {
	pthread_t tids[2];

	sem_init(&mutex, 0, 1);
	sem_init(&vazio, 0, 1);
	sem_init(&cheio, 0, 0);

	buffer[0] = 0; // indica que posição 0 está livre

	pthread_create(&tids[0], NULL, produtora, NULL);
	pthread_create(&tids[1], NULL, consumidora, NULL);
	
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	
	return 0;
}

void *produtora(void *param) {
	printf("Iniciando produtora...\n"); 
	
	while(1) {
		sem_wait(&mutex);
		sem_wait(&vazio);
		printf("Dado sendo produzido.\n");
		buffer[0] = 1;
		sem_post(&cheio);
		sem_post(&mutex);
	}
}

void *consumidora(void *param) {
	printf("Iniciando consumidora...\n");

	while(1) {
		sem_wait(&cheio);
		sem_wait(&mutex);				
		printf("Dado sendo consumido.\n");
		buffer[0] = 0;
		sem_post(&mutex);		
		sem_post(&vazio);
	}
}
