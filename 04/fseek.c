#include <stdio.h>
int main() {
    FILE *fp = fopen("fseek.c", "r");
    if (fp == NULL) return 1;

    printf("Pos: %ld\n", ftell(fp));
    char c;
    fread(&c, sizeof(c), 1, fp);
    printf("Val: %c\n", c);
    printf("Pos: %ld\n", ftell(fp));

    char s[10];
    fread(&s, sizeof(c), 10, fp);
    printf("Val: %s\n", s);
    printf("Pos: %ld\n", ftell(fp));

    fseek(fp, 0, SEEK_SET);

    fread(&s, sizeof(c), 10, fp);
    printf("Val: %s\n", s);
    printf("Pos: %ld\n", ftell(fp));

}