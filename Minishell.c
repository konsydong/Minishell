#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <fcntl.h>
#include <termio.h>
#define MAXLINE 1024
int count=0;
char cmdline[MAXLINE+1];

void sigint_handler(int sig);

void setup(void){
	signal(SIGINT,sigint_handler);
    signal(SIGINT,SIG_IGN);
}

void sigint_handler(int sig){
	printf("\n[Minishell]$ ");
	fflush(stdout);
}

void init(void){
    printf("\n[Minishell]$ ");
	fflush(stdout);
}
/*
int read_command(){
	if(fgets(cmdline,MAXLINE,stdin)==NULL)
		return -1;
	return 0;
}
*/

int scanKeyboard(){  
    int in;  
    struct termios new_settings;  
    struct termios stored_settings;  
    tcgetattr(0,&stored_settings);  
    new_settings = stored_settings;  
    new_settings.c_lflag &= (~ICANON);  
    new_settings.c_cc[VTIME] = 0;  
    tcgetattr(0,&stored_settings);  
    new_settings.c_cc[VMIN] = 1;  
    tcsetattr(0,TCSANOW,&new_settings);  
  
    in = getchar();
    ++count;
	fflush(stdout);
  
    tcsetattr(0,TCSANOW,&stored_settings);  
    return in;  
}


void shell_loop(void){
	int input;
	int i;
	while(1){
		init();
	/*	if(read_command()==-1)
			break;*/
		fflush(stdout);
	    while(input=scanKeyboard()){
            switch(input){
			    case 127:
					if(count){
						printf("\b \b\b \b\b \b");
						count-=3;
					}
					break; //Backspace
		        case 1:printf("\b \b\b \b\r");for(i=0;i<2;++i)printf("\t");printf("\b\b\b");break;              //ctrl+A
			    case 5:printf("\n\b");break;            // ctrl+E
	    	}
	   }
	}
	printf("\nexit\n");
}

int main(void){
	setup();
	shell_loop();

    return 0;
}
