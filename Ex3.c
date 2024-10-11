#include <stdio.h>
#include <pthread.h>

void *threadA() {
    printf("Thread A\n");
    
    pthread_exit(NULL);
}

void *threadB() {
    printf("Thread B\n");
    pthread_exit(NULL);
}

void *threadC() {
    printf("Thread C\n");
    pthread_exit(NULL);
}

void *threadD() {
    printf("Thread D\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3, thread4;

    
    pthread_create(&thread1, NULL, threadA, NULL);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, threadC, NULL);
    pthread_join(thread2, NULL);
    printf("Result of A->C\n");

    
    
    pthread_create(&thread3, NULL, threadD, NULL);
    pthread_join(thread3, NULL);
    printf("Result of D\n");


    pthread_create(&thread4, NULL, threadB, NULL);
    pthread_join(thread4, NULL);
    printf("Result of B\n");

    return 0;
}
