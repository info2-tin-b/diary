#include <stdio.h>

int main() {
    FILE *fp = fopen("utf8.txt", "r");
    if (fp == NULL) { return 2; }
    while(!feof(fp)) {
        //printf("0x%hhx\n", fgetc(fp));
        printf("%c", fgetc(fp));
    }
    fclose(fp);
}