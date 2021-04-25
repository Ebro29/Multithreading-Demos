//Ebrahim Shahid
//Operating Systems Project 2C
//The efficiency of threading in the C programming language

#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <time.h>

int const MAX = 15001; //Maximum numbers to compute is 15000 which will be used in a for loop and to avoid segmentation faults

//Function Declarations
void min(int *);
void max(int *);
void average(int *);
void createFile(char file[40]);
void fillArray(int *, char file[40]);


//main function
int main() {

   char input[40] = "input.txt";
   int r[MAX];
   pthread_t thread1, thread2, thread3;
   createFile(input);
   fillArray (r, input);
   //printf("Array elements after reading from file\n");
   //print(r);

   clock_t t;
   t = clock();

   //create thread1
   pthread_create(&thread1, NULL, (void *) min, (void *) &r);
   //create thread2
   pthread_create(&thread2, NULL, (void *) max, (void *) &r);
   pthread_create(&thread3, NULL, (void *) average, (void *) &r);

   //join threads
   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);
   pthread_join(thread3, NULL);
   t = clock() - t;
   double taken1 = ((double) t) / CLOCKS_PER_SEC; // in seconds
   printf ("Time taken is: %0.10lf\n", taken1);
   t = clock();
   min(r);
   max(r);
   average(r);
   t = clock() - t;
   double taken2 = ((double) t) / CLOCKS_PER_SEC; // in seconds
   printf ("Time taken is: %0.10lf\n", taken2);

   if(taken1 < taken2)
       printf("The solution with threads is better\n");
   else
       printf("The solution without threads is better\n");

   return 0;

}

void createFile(char file[40]) {

   int lower = -200, upper = 200, count = MAX; //Create a file with numbers ranging from -200 to 200 with 15,000 integers
   int i;

   srand(time(0));

   FILE *fptr;

   // integer variable
   int num;

   // open the file in write mode
   fptr = fopen(file, "w");
   if (fptr != NULL) {
       printf("File created successfully!\n");
   } else {
       printf("Failed to create the file.\n");
   }

   for (i = 0; i < count; i++) {
       int num = (rand() % (upper - lower + 1)) + lower;
       //putw(num, fptr);
        fprintf(fptr, "%d ", num);
       //printf("--%d", num); commented out to not display all 15,000 numbers on the console
   }

      fclose(fptr);
}

void fillArray(int *a, char file[40]) {

   FILE *f = fopen(file, "r");
   int i = 0;
   int num;
   while (fscanf(f, "%d", &num) > 0) {
       a[i] = num;
       i++;
   }
   fclose(f);
}

void min(int *pnum_times) {
   int i, mn = pnum_times[0];

   for (i = 1; i < MAX; i++) {
       if (pnum_times[i] < mn) {
           mn = pnum_times[i];
       }
   }
   printf("The minimum is: %d\n", mn);
}

void max(int *pnum_times) {
   int i, mx = pnum_times[0];

   for (i = 1; i < MAX; i++) {
       if (pnum_times[i] > mx) {
           mx = pnum_times[i];
       }
   }
   printf("The maximum is: %d\n", mx);
}

void average(int *pnum_times) {
   int i, sum = 0;

   for (i = 1; i < MAX; i++) {
       sum += pnum_times[i];
   }

   double a = sum/MAX;
   printf("The average is: %0.lf\n", a);
}

