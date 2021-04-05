#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
        
        pid_t pid = fork();
        if(pid == 0)
                execlp("/bin/ls", "ls", NULL);
        else {
                printf("Filho ingrato! Nao quer ser igual a mim.\n");
                wait(NULL);
        }

        return 0;
}
