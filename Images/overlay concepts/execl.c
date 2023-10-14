#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Transfer to execl function \n");
	execl("/usr/bin/head", "head", "-4", "f1", NULL);
	printf("This line will not execute \n");
	return 0;
}
