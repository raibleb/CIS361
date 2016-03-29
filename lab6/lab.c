/*
  Brett Raible & Yonglei Tao
  Date: 3/14/2015
  Lab 6
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 80
#define MAXARG 20

void background(char* cmd);

int main(int argc, char* argv[]) {
	char cmd[MAXLINE];
	int pid;	//Process ID
	for(; ;) {
		printf("mysh$ ");
		fgets(cmd, MAXLINE, stdin);	//Get command from the user
		if(strcmp(cmd, "exit\n")==0 || strcmp(cmd, "q\n")==0) {
			exit(0); //Exit if desired
		}
		pid = fork();
		if(pid) {
			//Parent
			wait(NULL);	//Wait for a child to return
		} else {
			//Child
			background(cmd);//Child uses this function
		}
	}
	return 0;
}

void background(char* cmd) {
	int i = 1;	
	char* argv[MAXARG];
	argv[0] = strtok(cmd, "\t \n");	//Tokens include \t's and \n's
	while(1) { //While TRUE
		argv[i] = strtok(NULL, "\t \n");
		if(argv[i] == NULL)
			break;
		i++;
	}
	execvp(argv[0], argv);	//Execute the process
	exit(0);
}
