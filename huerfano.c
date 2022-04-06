#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main(){   
    int pid = fork();
    if (pid > 0) printf("Soy padre\n");
    else if (pid == 0) {
        sleep(5);
        printf("ppid padre: %d\n", getppid());
        printf("Soy hijo\n");
    }
    return 0;
}