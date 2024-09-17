#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefd[2];  
    pid_t pid1, pid2;

    
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    
    if ((pid1 = fork()) == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) { 
        
        close(pipefd[0]);

        
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        
        printf("Message from first child\n");

        _exit(0);
    }

    
    if ((pid2 = fork()) == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) {  
        
        close(pipefd[1]);

        
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        /
        char buffer[100];
        ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  
            printf("Message received by second child: %s", buffer);
        }

        _exit(0);
    }

    
    close(pipefd[0]);
    close(pipefd[1]);

    
    wait(NULL);
    wait(NULL);

    return 0;
}

