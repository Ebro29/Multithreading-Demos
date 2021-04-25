//Ebrahim Shahid
//Operaing Systems Project2A
//Displaying an amount of numbers from the Fibonacci sequence using multithreading in C++

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<pthread.h>
#include<errno.h>
#include <stdlib.h>
#include <signal.h>

int fib0[100];
int fib1[100];
int fib2[100];

void *myThreadFunc0(void *vargp)
{
    int *p = (int *)vargp;
    fib0[0] = 0;
    fib0[1] = 1;
    int l;
    //printf("%d\n",*p);
    for (l = 2; l<*p; l++){
       fib0[l] = fib0[l-1]+ fib0[l-2];
    }
    return NULL;
}


void *myThreadFunc1(void *vargp)
{
    int *p = (int *)vargp;
    fib1[0] = 0;
    fib1[1] = 1;
    int l;
    //printf("%d\n",*p);
    for (l = 2; l<*p; l++){
       fib1[l] = fib1[l-1]+ fib1[l-2];
    }
    return NULL;
}


void *myThreadFunc2(void *vargp)
{
    int *p = (int *)vargp;
    fib2[0] = 0;
    fib2[1] = 1;
    int l;
    //printf("%d\n",*p);
    for (l = 2; l<*p; l++){
       fib2[l] = fib2[l-1] + fib2[l-2];
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t *tid;
    tid = (pthread_t *)malloc(sizeof(pthread_t) * atoi(argv[1]));
    int *count = (int *) malloc(sizeof(int) * atoi(argv[1]));
    int i;
    int n = atoi(argv[1]);
    int j = n-1;
    int k = n+ 1;

    pthread_create(&tid[0], NULL, myThreadFunc0, &n);
    pthread_create(&tid[1], NULL, myThreadFunc1, &j);
    pthread_create(&tid[2], NULL, myThreadFunc2, &k);


    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    printf("The Fibonacci sequence with the amount of #s you selected is:\n"); //Child thread
    for (i = 0; i<n; i++){
       printf("%d ", fib0[i]);
    }
    /*printf("\n");
    printf("Sequence by fib2:\n"); //Fibonacci sequence with 1 number less
    for (i = 0; i<j; i++){
       printf("%d ", fib1[i]);
    }
    printf("\n");
    printf("Sequence by fib3:\n"); //Fibonacci sequence with 1 number more
    for (i = 0; i<k; i++){
       printf("%d ", fib2[i]);
    }
    */
    printf("\n");
    exit(0);
}

//Execute by using :
//g++ -o Proj2A osproj2a.cpp -pthread
//./Proj2A n
//n = number of Fibonnacci sequence numbers you want
//using cin and cout caused Segmentation faults so I had to use this solution to prevent that
