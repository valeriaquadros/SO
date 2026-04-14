/**
 * Programa que cria duas threads: uma que quer escrever em buffer (produtora)
 * e outra que quer ler desse mesmo buffer (consumidora).
 *
 * É possível que na tela de saída apareçam duas mensagens "Dado sendo produzido."
 * (ou "Dado sendo consumido.") seguidas? Por que?
 *
 * Para compilar:
 * gcc -o sem_espera_ocupada sem_espera_ocupada.c -pthread
 *
 * Para executar:
 * ./sem_esperar_ocupada > x
 * Depois abra o arquivo x e verifique o que há nele.
 */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int buffer[1];
void *produtora(void *param);
void *consumidora(void *param);

sem_t mutex;

int main(int argc, char *argv[]) {
	pthread_t tids[2];

	sem_init(&mutex, 0, 1);
	
	buffer[0] = 0; // indica que posição 0 está livre

	pthread_create(&tids[0], NULL, produtora, NULL);
	pthread_create(&tids[1], NULL, consumidora, NULL);
	
	pthread_exit(NULL);

	return 0;
}

void *produtora(void *param) {
	printf("Iniciando produtora...\n"); 
	
	while(1) {
		
		sem_wait(&mutex);

		if(buffer[0] == 0) {
			printf("Dado sendo produzido.\n");
			buffer[0] = 1;
		}
		else {
			while(buffer[0] == 1) {
				; // não faz nada
			}
		}
		sem_post(&mutex);
		
	}
}

void *consumidora(void *param) {
	printf("Iniciando consumidora...\n");

	while(1) {
		
		sem_wait(&mutex);

		if(buffer[0] == 1) {
			printf("Dado sendo consumido.\n");
			buffer[0] = 0;
		}
		else {
			while(buffer[0] == 0) {
				; // não faz nada
			}			
		}
		sem_post(&mutex);
		
	}
}
