#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr, *buffer;
    key_t key;

    // Generate a key for the shared memory segment
    key = ftok(".", 's');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
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

    // Read from standard input and write to shared memory
    buffer = malloc(SHM_SIZE);
    if (!buffer) {
        perror("malloc");
        exit(1);
    }

    printf("Enter data to write to shared memory (max %d bytes):\n", SHM_SIZE - 1);
    fgets(buffer, SHM_SIZE, stdin);

    strncpy(shmaddr, buffer, SHM_SIZE - 1);
    shmaddr[SHM_SIZE - 1] = '\0';

    printf("Data written to shared memory: %s\n", shmaddr);

    // Detach and remove the shared memory segment
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

