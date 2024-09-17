#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {  
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {  
        printf("Child process (PID: %d)\n", getpid());
        
    } else {  
        int status;
        printf("Parent process (PID: %d), waiting for child...\n", getpid());
        pid_t wpid = wait(&status);  

        if (wpid == -1) {
            perror("wait failed");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child process (PID: %d) exited with status %d\n", wpid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process (PID: %d) was terminated by signal %d\n", wpid, WTERMSIG(status));
        }
    }

    return 0;
}


/**********************
Sara Adhikari 
Question 
What happens if
you use wait() in the child?
-> using wait() in  child process leads to the child process waiting for a child process of its own to terminate.

**************** */