#include<stdio.h>
#include<unistd.h>

int main(void) {
        int variavel;
        pid_t pid = fork();
        if(pid == 0)
                execlp("/bin/ls", "ls", NULL);
        else {
                printf("Filho ingrato! Nao quer ser igual a mim.\n");
                wait(NULL);
        }
        return 0;
}
