#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if(rc == 0){ //child
		printf("Test print in child before close function\n");
		close(STDOUT_FILENO);
		printf("Test print in child after close function");
	}
	else{
		printf("Parent of %d (pod:%d) \n", rc, (int) getpid());
	}
	return(0);
}
