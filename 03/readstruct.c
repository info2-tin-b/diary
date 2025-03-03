#include <stdio.h>
#include <stdint.h>

typedef struct datetime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    char day_name[16];
} DateTime;

int main() {
    FILE *fp = fopen("answer", "r");
    if (fp == NULL) return 2;

    DateTime now;

    fread(&now, sizeof(DateTime), 1, fp);

    printf("%hd-%hhd-%hhd (%s)\n", now.year, now.month, now.day, now.day_name);
    fclose(fp);
}