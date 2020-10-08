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

float pow(float x, int y) {
    if(x < 0 || y < 0){
        return -1;
    } else {
        if(x == 0){
            if(y == 0){
                return -1;
            } else {
                return 0;
            }
        } else {
            float i = x;
            for (int i = 1; i < y; i++){
                i *= x;
            }
            return i;
        }
    }
}

float taylor_series_sin(float radian) {
    float result = 0.0f;
    for (int i = 1; i <= 7; i++){
        if(i % 2 == 1){
            float a = pow(radian, 2 * i - 1) / factorial(2 * i - 1);
            result += a;
        } else {
            float a = pow(radian, 2 * i - 1) / factorial(2 * i - 1);
            result -= a;
        }
    }
    return result;
}

int main() {
    const float PI = 3.14159265f;
    float radian = PI / 3.0f;
    printf("sin(%f) = %f", radian, taylor_series_sin(radian));
    return 0;
}