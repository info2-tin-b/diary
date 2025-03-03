#include <stdio.h>
#include <stdint.h>

typedef struct datetime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    char day_name[16];
} DateTime;

int main() {
    FILE *fp = fopen("answer", "w");
    if (fp == NULL) return 2;

    DateTime now = {.year=2025, .month=3, .day=3, .day_name="monday"};

    fwrite(&now, sizeof(DateTime), 1, fp);

    fclose(fp);
}