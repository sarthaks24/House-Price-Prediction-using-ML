// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
	long mtype;
	char buff[100];
} x;

int main()
{
	key_t key;
	int mid;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget creates a message queue
	// and returns identifier
	mid = msgget(key, 0666 | IPC_CREAT);

	// msgrcv to receive message
	msgrcv(mid, &x, sizeof(x), 1, 0);

	// display the message
	printf("Data Received is : %s \n",
					x.buff);

	// to destroy the message queue

	return 0;
}
