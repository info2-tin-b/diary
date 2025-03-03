#include <stdio.h>

int main() {
    FILE *fp = fopen("answer", "w");
    if (fp == NULL) return 2;

    // fputc('4', fp); 
    // fputc(0x32, fp);
    //fputs("12345", fp);

    int number = 12267037; // 0x00'00'30'39

    fwrite(&number, 4, 1, fp);

    fclose(fp);
}