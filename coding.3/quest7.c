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
        close(STDOUT_FILENO);

        
        printf("This will not be printed because STDOUT is closed.\n");

        
        fprintf(stderr, "This will be printed to standard error.\n");

        _exit(0);  
    } else {  
       

        printf("Parent process (PID: %d)\n", getpid());
    }

    return 0;
}

/*************
Sara Adhikari 
Question 
"What happens to the print statement?"
->  It does not print anything to the console, as standard output has been closed.

********* */