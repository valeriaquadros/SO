#include<stdio.h>
#include<unistd.h>

int main(void) {
 
        pid_t pid = fork();
        if(pid == 0)
                printf("Filho\n");
        else
                if(pid > 0)
                      printf("Pai\n");
                else
                      printf("Erro: não foi possível criar filho.");

		fflush(NULL);
    return 0;
}
