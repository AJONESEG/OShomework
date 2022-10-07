#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int x = 100;
	printf("hello world (pid:%d) \n", (int) getpid());
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if(rc == 0){ //child
		printf("Child, (pid:%d)\n", (int) getpid());
		x = 200;
		printf("x in child is: %d\n", x);
	}
	else{
		printf("Parent of %d (pod:%d) \n", rc, (int) getpid());
		x = 150;
		printf("x in parent is: %d\n", x);
	}
	printf("final value of x is: %d\n", x);
	return(0);
}
