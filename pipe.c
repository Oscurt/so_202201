#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    int channel[2];
    pipe(channel);
    for(int i=0;i<16;i++){
        if(!fork()){
            srand(getpid()); // comentar esta linea en caso de no usar rand()
            close(channel[0]);
            int number = rand() % 1000; // getpid(); // se puede probar con getpid(), para comprobar que son procesos distintos :)
            write(channel[1], &number, sizeof(number));
            exit(0);
        }
    }
    close(channel[1]);
    int status = 0;
    int total = 0;
    while(wait(&status) > 0){
        int res;
        read(channel[0], &res, sizeof(res));
        printf("%d\n", res);
        total = total + res;
    }

    printf("total: %d\n", total);

    return 0;
}