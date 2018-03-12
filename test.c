#include <stdio.h>
#include <stdlib.h>

int main(){
    system("stty raw echo");
    getchar();
    system("stty cooked echo");

    return 0;
}

