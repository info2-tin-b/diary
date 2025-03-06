#include <stdio.h>

int main() {
    FILE *fp = fopen("poeme.txt", "r");

    char buffer[10];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("[%s]", buffer);
    }
}