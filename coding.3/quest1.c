#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 200;
    pid_t mc = fork();

    if (mc == -1) {
        perror("fork failed");
        return 1;
    }

    if (mc == 0) {  
        printf("Child process: x = %d\n", x);
        x = 200;
        printf("Child process after modification: x = %d\n", x);
    } else {  
        printf("Parent process: x = %d\n", x);
        x = 300;
        printf("Parent process after modification: x = %d\n", x);
    }

    return 0;
}

/********************************************* 
Question 1 : "What value is the variable in the child process"?
-> The value of x in the child process is 200. The child process inherits the value of x from the parent at the time of the fork.

Question 2 : "What happens to the variable when both the child and parent change
the value of x?
-> the child and parent processes each have their own separate copy of the variable x, so changes to x in one process do not affect the other. Thus, in the child process, x remains 200, while in the parent process, x changes to 300.

*********************/