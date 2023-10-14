#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

sem_t x, y;
pthread_t tid;
pthread_t writerthreads[50], readerthreads[50];
int readercount;

void* reader(void* param) {
    // Code for reader thread
    sem_wait(&y);
    readercount++;
    if (readercount == 1) {
        sem_wait(&x);
    }
    sem_post(&y);

    printf("Reading...\n");
    // Reading...

    sem_wait(&y);
    readercount--;
    if (readercount == 0) {
        sem_post(&x);
    }
    sem_post(&y);
}

void* writer(void* param) {
    // Code for writer thread
    sem_wait(&x);

    printf("Writing...\n");
    // Writing...

    sem_post(&x);
}

int main() {
    int n2, i;
    printf("Enter the number of readers: ");
    scanf("%d", &n2);
    int n1[n2];
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    readercount = 0;

    for (i = 0; i < n2; i++) {
        pthread_create(&readerthreads[i], NULL, reader, NULL);
        pthread_create(&writerthreads[i], NULL, writer, NULL);
    }

    for (i = 0; i < n2; i++) {
        pthread_join(writerthreads[i], NULL);
        pthread_join(readerthreads[i], NULL);
    }

    return 0;
}
