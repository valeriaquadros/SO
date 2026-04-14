/**
 * Implementa uma função de multiplicação que acumula valores em uma variável de
 * uma thread separada. 
 *
 * Para compilar: 
 * gcc exemplo_thread2 exemplo_thread2.c
 * Exemplo de execução:
 * ./exemplo_thread2 100000
 *
 * Execute o programa com um número crescente de n. Comece com n=1 e verifique 
 * o montante de CPU que o programa está usando 
 * (comando top). Depois execute com n=2 e, em seguida, n=3, n=4... O que 
 * acontece com o uso de CPU? Por que?
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void *runner(void *param); /* função que será executada pela thread */

int main(int argc, char *argv[])
{
    void *retval;
    int ret;
	pthread_t tid; /* identificador da thread */
	int n_threads;
	int num_iter;

	if (argc != 3) {
		fprintf(stderr,"Uso: ./exemplo_thread2 <num_threads> <num_iter>\n");
		/* retorna indicando erro: exit(1);*/
		return -1;
	}

	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"O argumento %d deve ser um inteiro positivo\n",atoi(argv[1]));
		/*exit(1);*/
		return -1;
	}
	
	n_threads = atoi(argv[1]);
	num_iter = atoi(argv[2]);   
	
	pthread_t *threads = malloc(n_threads * sizeof(pthread_t));
    if (threads == NULL) {
        perror("Erro ao alocar memória");
        return EXIT_FAILURE;
    }

    // Cria as threads
    for (int i = 0; i < n_threads; i++) {               
        if (pthread_create(&threads[i], NULL, runner, (void *)(intptr_t)num_iter) != 0) {
            perror("Erro ao criar thread");
            free(threads);
            return EXIT_FAILURE;
        }
    }

    // Espera todas as threads terminarem
    for (int i = 0; i < n_threads; i++) {
        void *retval;
        pthread_join(threads[i], &retval);
        int ret = (intptr_t)retval;
        if (ret == 0)
            printf("Thread %d terminou com sucesso!\n", i);
        else
            printf("Thread %d finalizou com erro: %d!\n", i, ret);
    }

    free(threads);
    return EXIT_SUCCESS;
}

/**
 * A thread inicia a execução nessa função que é CPU-bound.
 */
void *runner(void *param) 
{
	int k = 1;
	int i, j;
	int limit = (intptr_t)param;
	for(i = 0; i < limit; i++) {
		for(j = 0; j < 100000; j++)
			k = k * 1;
	}
    
	// Se rodou "tudo bem", retorne 0
    	pthread_exit((void*)(intptr_t)0);

    	// Caso queira simular erro, poderia retornar -1
    	// pthread_exit((void*)(intptr_t)-1);
}

