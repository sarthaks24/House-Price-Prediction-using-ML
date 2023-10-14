#include <stdio.h>
#include<unistd.h>
int main()
{
printf("Transfer to execlp function \n");
execlp("./helloworld", "./helloworld",(char*)0);
printf("This line will not execute \n");
return 0;
}

// gcc helloworld -o helloworld
// gcc overlay -o overlay 
// ./overlay
