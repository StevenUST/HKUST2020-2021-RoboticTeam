#include <stdint.h>
#include <stdio.h>

long factorial(long i) {
    if(i == 0 || i == 1){
        return 1;
    } else {
        long a = 1;
        for (long j = i; j > 1; j--)
        {
            a *= j;
        }
        return a;
    }
}

int main() {
    for (long i = 0; i < 15; i++) {
        printf("%ld! = %ld\n", i, factorial(i));
    }
    return 0;
}