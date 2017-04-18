#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <time.h>
#define SIZE 10000


 int nbr_thread, i, thread_id;
int X[SIZE],Y[SIZE],Z[SIZE]={0};
double sum_sequenciel(){
      clock_t start=clock();


    int i;
    for (i = 0; i < SIZE; i++) {
        Z[i]=(X[i]+Y[i]);
    }
     // Save end time
   clock_t end=clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double multi_thread_sum(int nb_threads){
clock_t start=clock();
#pragma omp parallel num_threads(nb_threads) private (i,thread_id) shared (Z)
 {


 #pragma omp for
 for(i = 0; i < SIZE; i++){
 Z[i] = (X[i] + Y[i]);
 }
 //thread_id = omp_get_thread_num ( );
 }
 clock_t end=clock();

return (double)(end - start) / CLOCKS_PER_SEC;
}
int main()
{
        ///initilize arrays with random numbers not larger than 100
        srand(0);
        int i;
        for (i = 0; i < SIZE; i++) {
        X[i] = rand()%100;
        Y[i] = rand()%100;
        }
        printf("it took %.6f time for the sequenciel version \n",sum_sequenciel());
        printf("it took %.6f time for the multi thread version 2 thrads\n",multi_thread_sum(2));
    return 0;
}