/*

Write a C program that creates two child processes: A and B.
Process B generates one random number N between 100 and 1000.
Process A keeps generating and sending random numbers between
50 and 1050 to B until the absolute difference between N and
a number is less than 50.
B prints the generated numbers and all the received numbers.
A sends to the parent the number of numbers generated until
the condition was met, and the parent prints it.
The processes communicate through pipes.

Example:
Process B has generated 433
B received 244; difference: 189
B received 367; difference: 66
B received 723; difference: 290
B received 465; difference: 32
Process A has generated 4 numbers

*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
        srand(time(0));
        int a2b[2], b2a[2], a2p[2];
        if(pipe(a2b) == -1){
                perror("pipe a2b f!");
                exit(1);
        }
        if(pipe(b2a) == -1){
                perror("pipe a2b f!");
                exit(1);
        }
        if(pipe(a2p) == -1){
                perror("pipe a2p f!");
                exit(1);
        }

        pid_t A, B;
        A = fork();
        B = fork();
        if(A == -1){
                perror("A proc failed");
                exit(1);
        }
        else if(A == 0){//A child
                close(a2b[0]);
                close(b2a[1]);
                close(a2p[0]);
                int nb=0;
                int res=0;
                while(res != -1){
                        nb = rand() % 1001 + 50;
                        write(a2b[1], &nb, sizeof(int));
                        read(b2a[0], &res, sizeof(int));
                }
                int knb=0;
                read(b2a[0], &knb, sizeof(int));
                write(a2p[1], &knb, sizeof(int));
                close(a2b[1]);
                close(b2a[0]);
                close(a2p[1]);
        }
        //B = fork();
        if(B == -1){
                perror("B proc failed");
                exit(1);
        }
        else if(B == 0){//child B
                close(a2b[1]);
                close(b2a[0]);
                int diff = 1000;
                int aNb=0;
                int k=0;
                int nb = rand() % 901 + 100;
                printf("B gen %d\n", nb);
                while(diff >= 50){
                        read(a2b[0], &aNb, sizeof(int));
                        //printf("A sent %d\n", aNb);
                        k++;
                        diff= abs(nb - aNb);
                        printf("A sent %d and diff is: %d\n", aNb, diff);
                        if(diff >= 50)
                                write(b2a[1], &diff, sizeof(int));
                        else{
                                int x =-1;
                                write(b2a[1], &x, sizeof(int));
                        }
                }write(b2a[1], &k, sizeof(int));
                close(a2b[0]);
                close(b2a[1]);
        }
        //parent
        close(a2p[1]);
        int res = 0;
        read(a2p[0], &res, sizeof(int));
        if(res!=0)
                printf("A gen %d nbs\n", res);
        close(a2p[0]);
        exit(0);
        return 0;
}
                                                                                85,1          Bot
