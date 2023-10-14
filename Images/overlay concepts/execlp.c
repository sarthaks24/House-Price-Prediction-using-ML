#include <stdio.h>
#include <unistd.h>
int main()
{
    	printf("transfer to execlp function\n");
    	execlp("head","head","-2","f1",NULL);
    	printf("this line will not be executed");
    	return 0;
}
