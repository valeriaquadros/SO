#include<stdio.h>
#include<unistd.h>

int main(void) {
        int y;
        pid_t pid = fork();
        if(pid == 0)
                y = 10;
        else 
                y = 100;
        printf("%d\n", y);
        return 0;
}
