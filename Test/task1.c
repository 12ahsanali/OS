// Write a C program that creates 4 threads. Each thread should:
 
// 1.  Receive a unique number N as an argument (use values: 10, 20, 30, 40)

// 2.  Calculate the sum of numbers from 1 to N

// 3.  Print the thread number and calculated sum

// 4.  Return the sum through thread's return value

// Main thread should:
//   Create all 4 threads and pass arguments Wait for all threads to complete
//  Collect all return values
//  Calculate and print the total of all sums


// roll no :23-ntu-cs-1130
// name : Ahsan Ali

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

void* cal_sum(void* arg){
    int N=*((int*)arg);
    int sum=0;  
    for (int i=1;i<=N;i++){
        sum+=i;
    }
    printf("thread for N=%d calculated sum=%d\n",N,sum);

    int* result=malloc(sizeof(int));
     *result=sum;
    pthread_exit((void*)result);
}
int main(){
    pthread_t thread[4];
    int args[4]={10,20,30,40};
    int* ret_vals[4];
    int total=0;

    for (int i=0;i<4;i++){
        int* arg=malloc(sizeof(int));
        *arg=args[i];
         if(pthread_create(&thread[i],NULL,cal_sum,(void*)arg)){
            perror("error in creating thread");
            return 1;
         }
        }

        for (int i=0;i<4;i++){
            pthread_join(thread[i],(void**)&ret_vals[i]);
            total=total+ *ret_vals[i];
            free(ret_vals[i]);
                 }
    printf("total sum from all threads=%d\n",total);
    return 0;
        }
