#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;

    key_t key;

    // Generate a key for the shared memory segment
    key = ftok(".", 's');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment
    shmaddr = (char *) shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read from shared memory and write to standard output
    printf("Data read from shared memory: %s\n", shmaddr);

    // Detach the shared memory segment
    shmdt(shmaddr);

    return 0;
}

