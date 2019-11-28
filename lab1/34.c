#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

    int n;
    pid_t pid;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        pid = fork();
        printf("Sou o processo %ld.\n", pid);
    
        // if (pid != 0) {
        //     printf("%ld, I am your father.\n", pid);
        // } else {
        //     printf("NOOOOOOOOOOOOOOOOOOOOOO\n");
        // }
    }


    // pid = fork();

    // if (pid != 0) {
    //     printf("%ld, I am your father.\n", pid);
    // } else {
    //     printf("NOOOOOOOOOOOOOOOOOOOOOO\n");
    // }

    printf("Sou o processo %ld.\n", pid);

    return 0;
}