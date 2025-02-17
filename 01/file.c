#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "a");
    fwrite("prout", 5, 1, fp);
    fclose(fp);
}