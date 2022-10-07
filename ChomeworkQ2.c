#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
	int file = open("testFile.txt",O_RDWR |  O_CREAT );
	printf("hello world (pid:%d) \n", (int) getpid());
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if(rc == 0){ //child
		printf("Child, (pid:%d)\n", (int) getpid());
		write(file, "Child is writing to file\n",30);
	}
	else{
		printf("Parent of %d (pod:%d) \n", rc, (int) getpid());
		write(file, "Parent is writing to file\n", 30);
	}
	return(0);
}
