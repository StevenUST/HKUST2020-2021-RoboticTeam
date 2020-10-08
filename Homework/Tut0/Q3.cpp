#include <stdint.h>
#include <stdio.h>
#include <string.h>

const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;

int valuereturn(char a){
    int result = 0;
    switch (a)
    {
    case 'I':
        result = I;
        break;
    case 'V':
        result = V;
        break;
    case 'X':
        result = X;
        break;
    case 'L':
        result = L;
        break;
    case 'C':
        result = C;
        break;
    case 'D':
        result = D;
        break;
    case 'M':
        result = M;
        break;
    default:
        break;
    }
    return result;
}

int roman_to_int(const char s[], int length) {
    int result = 0;
    for (int i = 0; i < length; i++){
        int a = valuereturn(s[i]);
        if(i == 0){
            result += a;
        } else {
            int b = valuereturn(s[i - 1]);
            if(b < a){
                result = result - b * 2 + a;
            } else {
                result += a;
            }
        }
    }
    return result;
}

int main() {
    char roman_num[] = "III";
    char roman_num_2[] = "CXXIII";
    char roman_num_3[] = "MMMCDLIX";

    printf("roman_to_int(%s) = %d\n", roman_num,
           roman_to_int(roman_num, strlen(roman_num)));
    printf("roman_to_int(%s) = %d\n", roman_num_2,
           roman_to_int(roman_num_2, strlen(roman_num_2)));
    printf("roman_to_int(%s) = %d\n", roman_num_3,
           roman_to_int(roman_num_3, strlen(roman_num_3)));
    return 0;
}