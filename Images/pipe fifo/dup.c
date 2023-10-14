#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        return 1;
    } else if (pid1 == 0) {
        // Child process 1: execute "ls -l" and write its output to the pipe
        close(pipefd[0]); // Close unused read end of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
        perror("execlp"); // This line will be reached only if execlp fails
        return 1;
    } else {
        pid_t pid2 = fork();
        if (pid2 == -1) {
            perror("fork");
            return 1;
        } else if (pid2 == 0) {
            // Child process 2: execute "wc -l" and read its input from the pipe
            close(pipefd[1]); // Close unused write end of the pipe
            dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the read end of the pipe
            execlp("wc", "wc", "-l", NULL); // Execute "wc -l"
            perror("execlp"); // This line will be reached only if execlp fails
            return 1;
        } else {
            // Parent process: wait for both child processes to finish and close the pipe
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
            return 0;
        }
    }
}

