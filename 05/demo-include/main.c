#include <pi.h>
#include <stdio.h>

#if !defined VALUE
#   define VALUE 42 
#endif 

int main() {
    printf("%f %d\n", PI, VALUE);
}