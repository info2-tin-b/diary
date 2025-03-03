#include <stdio.h>

int main(int argc, char*argv[]) {
    if (argc < 2) return 1;
    char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return 2;

    char c; 
    while((c = fgetc(fp)) != EOF ) {
        printf("%c", c);
    }
}