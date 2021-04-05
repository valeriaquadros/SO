#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
        int x;
        pid_t pid = fork();
        if(pid == 0)
                x = 10;
        else { 
                x = 100;
                wait(NULL);
        }
        printf("%d\n", x);
        return 0;
}
