#include <stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int p[2];
char buff[25];
pipe(p);
if(fork()==0)
{
printf("Child : Writing to pipe \n");
write(p[1],"Welcome",8);
printf("Child Exiting\n");
}
else
{
wait(NULL);
printf("Parent : Reading from pipe \n");
read(p[0],buff,8);
printf("Pipe content is : %s \n",buff);
}
return 0;
}
