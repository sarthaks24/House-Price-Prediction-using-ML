/*C program to get Process Id and Parent Process Id in Linux.*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int par_id, p_pid;

    par_id = getpid(); /*process id*/
   
    printf("Process ID: %d\n", par_id);
    printf("Parent Process ID: %d\n", p_pid);

    return 0;
}

