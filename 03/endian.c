#include <stdio.h>

int main() {
    char u[] = {0x00, 0x12, 0x24, 0x38};
    printf("%d\n", *(int*)&u);

    char v[] = {0x38, 0x24, 0x12, 0x00};
    printf("%d\n", *(int*)&v);


    FILE *fp = fopen("data.bin", "w");
    fwrite(&u, sizeof(int), 1, fp);
    fwrite(&v, sizeof(int), 1, fp);

    fclose(fp);
}