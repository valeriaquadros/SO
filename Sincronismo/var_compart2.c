/**
 * Programa que cria duas threads, ambas compartilhando a variável global count.
 * A condição de corrida acontece no método add. Se duas threads lerem o mesmo 
 * valor de count, ele não será incrementado como esperado.
 * Note que as variáveis locais de cada thread, tais como i e tmp do método
 * add, não são compartilhadas.
 *
 * Para compilar:
 * gcc -o  var_compart2 var_compart2.c -pthread
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 1000000

int count = 0;
//sem_t mutex; //XXX

void * add(void * a)
{
    int i, tmp; // i e tmp não são compartilhadas!
    for(i = 0; i < NITER; i++)
    {
//	sem_wait(&mutex); //XXX
        tmp = count;      // copy the global count locally 
        tmp = tmp+1;      // increment the local copy 
        count = tmp;      // store the local value into the global count 
//	sem_post(&mutex); //XXX
    }
}

int main(int argc, char * argv[])
{
    pthread_t tid1, tid2;
//    sem_init(&mutex, 0, 1);//XXX

    if(pthread_create(&tid1, NULL, add, NULL))
    {
      printf("\n ERRO ao criar thread 1");
      exit(1);
    }

    if(pthread_create(&tid2, NULL, add, NULL))
    {
      printf("\n ERRO ao criar thread 2");
      exit(1);
    }

    if(pthread_join(tid1, NULL))	// wait for thread 1
    {
      printf("\n ERRO ao esperar thread 1");
      exit(1);
    }

    if(pthread_join(tid2, NULL))        // wait for thread 2
    {
      printf("\n ERRO ao esperar thread 2");
      exit(1);
    }

    if (count < 2 * NITER) 
        printf("\n BOOM! count é [%d], mas deveria ser %d\n", count, 2*NITER);
    else
        printf("\n OK! count é [%d]\n", count);
  
    pthread_exit(NULL);
}


