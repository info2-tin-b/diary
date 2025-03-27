#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    while(1) {
        (void*)malloc(1024*1024);
        //usleep(10000);
    }
}