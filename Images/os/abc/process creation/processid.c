#include <stdio.h>
#include <unistd.h>

int main()
{
    int par_id, p_pid;

    par_id = getpid();

    printf("Process ID: %d\n", par_id);
    printf("Parent Process ID: %d\n", p_pid);

    return 0;
}
