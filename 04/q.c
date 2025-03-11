#include <stdio.h>
int main() {
    int value = 0x12345678;

    /*
    | 00  | 01  | 02  | 03  | 04  | 05  | 06  | 07  |
    | --- | --- | --- | --- | --- | --- | --- | --- |
    | 45  | 23  | 2e  | 1f  | 78  | 56  | 34  | 12  |
                              ^^
    */
    void *a = &value;
    a += 1; // Pas le droit 
    

    printf("%hhx\n", *a);
    printf("%p\n", a);
    
}