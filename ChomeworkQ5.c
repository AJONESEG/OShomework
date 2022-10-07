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
		int rc_wait = wait(NULL);
		printf("Child says Hello, Child ID: (pid:%d)\nWait ID is: (rc_wait:%d)\n", (int) getpid(),rc_wait);
	}
	else{
		//int rc_wait = wait(NULL);
		printf("Parents child is: %d (pid:%d)\n", rc, (int) getpid());
	}
	return(0);
}
