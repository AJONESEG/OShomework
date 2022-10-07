#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int x = 300;
//	printf("hello world (pid:%d) \n", (int) getpid());
	int rc = fork();
	if(rc < 0){
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if(rc == 0){ //child
		printf("Child says Hello\n ");
	}
	else{
		usleep(10*1000);
		printf("Parent says Goodbye\n");
		
	}
	return(0);
}
