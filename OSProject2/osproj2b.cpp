//Ebrahim Shahid
//Operating Systems Project 2B
//Printing Words with sched_yield()

#define _MULTI_THREADED
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
#define THREADS 2

using namespace std;

//Global variable definitions
int i=1;
int j;
int k;
int l;
int consonent;
char *vowel[1000];

//Thread function 
void *threadfunc(void *parm)
{
int *num;

num=(int*)parm;
while(1)
    {

    if(i>=consonent)
    break;

    if(*num ==1)
    if(vowel[i][0]=='a' ||vowel[i][0]=='e'||vowel[i][0]=='i' ||vowel[i][0]=='o' ||vowel[i][0]=='u' ||vowel[i][0]=='2') //Check for vowels
    {
    cout << "vow: ";
    printf("%s\n",vowel[i]);
    i++;
    continue;
    }

     if(*num ==2)
    if(!(vowel[i][0]=='a' ||vowel[i][0]=='e'||vowel[i][0]=='i' ||vowel[i][0]=='o' ||vowel[i][0]=='u' ||vowel[i][0]=='2')) //Check for consonents
    {
    cout << "cons: ";
    printf("%s\n",vowel[i]);
    i++;

    continue;
    }

    sched_yield();
    }
return NULL;
}

//Main Function
int main(int argc, char *argv[])
{
pthread_t threadid[THREADS];
int rc=0;
int letters=0;
int arr[2]={1,2};
consonent=argc;
for(rc=0;rc<argc;rc++)
    vowel[rc]=argv[rc];
printf("Creating %d threads\n", THREADS);
for (letters=0; letters<THREADS; ++letters) 
{
      rc =pthread_create(&threadid[letters], NULL, threadfunc,&arr[letters]);
}

for (letters=0; letters<THREADS; ++letters) 
{
    rc = pthread_join(threadid[letters], NULL);
}

printf("Main completed\n");
return 0;
}

