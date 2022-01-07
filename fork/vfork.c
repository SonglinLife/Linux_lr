#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    pid_t pid;
    pid = vfork();
    if (pid<0){
        printf("vfork error!\n");
        exit(1);
    }
    else if(pid==0){
        printf("Child process PID: %d.\n", getpid());
        char * argv[] = {"ls", "-al","/home",NULL};
        char * envp[] = {"PATH=/bin",NULL};
        if (execve("/bin/ls", argv, envp) < 0){
            printf("subprocess error");
            exit(1);
        }
    }
    else{
        printf("Parent process PID: %d.\n",getpid());
        sleep(1);
    }
    return 0;
}

