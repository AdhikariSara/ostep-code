#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {  // Error handling
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {  // Child process
        printf("hello\n");
        // Sleep to ensure that the parent prints after this
        sleep(1);
    } else {  // Parent process
        // Sleep to give child process a chance to run first
        sleep(2);
        printf("goodbye\n");
    }

    return 0;
}

/*************************
 can you do
this without calling wait() in the parent?
-> No. 

**************** */