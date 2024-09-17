#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("testfile.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    pid_t mc = fork();

    if (mc == -1) {
        perror("fork failed");
        return 1;
    }

    if (mc == 0) {  
        write(fd, "Child\n", 6);
        sleep(1);  // Delay to observe interleaving
    } else {  
        write(fd, "Parent\n", 7);
        sleep(1);  // Delay to observe interleaving
    }

    close(fd);
    return 0;
}
/*******************************
Sara Adhikari 
Question 
1) Can both the child
and parent access the file descriptor returned by open()?
-> Yes, both the child and parent processes can access the file descriptor returned by open(). 
What
happens when they are writing to the file concurrently, i.e., at the
same time?
-> can lead to unpredictable results due to the non-atomic nature of file writes.

 **************/