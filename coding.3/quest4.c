#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {  
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {  
        printf("Child process (PID: %d) using execl():\n", getpid());
        execl("/bin/ls", "ls", NULL);  // execl() example
        perror("execl failed");

        // Optionally, you can demonstrate other exec functions as well
        // Uncomment and test one at a time.

        // printf("Child process (PID: %d) using execle():\n", getpid());
        // execle("/bin/ls", "ls", NULL, NULL);  // execle() example
        // perror("execle failed");

        // printf("Child process (PID: %d) using execlp():\n", getpid());
        // execlp("ls", "ls", NULL);  // execlp() example
        // perror("execlp failed");

        // printf("Child process (PID: %d) using execv():\n", getpid());
        // char *argv[] = {"ls", NULL};
        // execv("/bin/ls", argv);  // execv() example
        // perror("execv failed");

        
        
    } else {  
        
        printf("Parent process (PID: %d)\n", getpid());
    }

    return 0;
}

/*************************
 Why do
you think there are so many variants of the same basic call?
-> Some variants simplify usage by automatically searching for executables in the PATH, while others offer fine-grained control over arguments and environment variables.


***********/