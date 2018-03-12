#include <termio.h>  
#include <stdio.h>  
  
  
int scanKeyboard()  
{  
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
  
tcsetattr(0,TCSANOW,&stored_settings);  
return in;  
}  

int main(){  
while(1){  
printf(":%d",scanKeyboard());  
}  
} 
