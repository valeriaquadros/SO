#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
        int variavel;
        pid_t pid = fork();
        if(pid == 0)
                variavel = 10;
        else { 
                variavel = 100;
                wait(NULL);
        }
        printf("%d\n", variavel);
        return 0;
}
