// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

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
	x.mtype = 1;

	printf("Write Data : ");
	fgets(x.buff,MAX,stdin);

	// msgsnd to send message
	msgsnd(mid, &x, sizeof(x), 0);

	// display the message
	printf("Data send is : %s \n", x.buff);

	return 0;
}
