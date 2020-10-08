#include <stdio.h>

int pow(int x, int y) {
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
            if(x > 0 && y == 0){
                return 1;
            } else {
                int a = x;
                for (int i = 1; i < y; i++){
                    a = a * x;
                }
                return a;
            }
        }
    }
}

int num_of_bits(int x)
{
    if(x == 0){
        return 1;
    } else {
        if(x > 0){
            int i1 = 0;
            while(true){
                if(x >= pow(10, i1)){
                    i1++;
                } else {
                    break;
                }
            }
            return i1;
        } else {
            x *= -1;
            int result = num_of_bits(x);
            return result;
        }
    }
}

int reverse(int x) {
    int result = 0;
    if (x == 0) {
        return 0;
    } else {
        int length = num_of_bits(x);
        int s[length];
        if (x > 0){
            int i = 1;
            while (true)
            {
                s[i - 1] = x % pow(10, 1);
                x /= pow(10, 1);
                i++;
                if(i > length){
                    break;
                }
            }
            for (int i = 0; i < length / 2; i++){
                int x = s[i];
                s[i] = s[length - i - 1];
                s[length - i - 1] = x;
            }
            for (int i = 0; i < length; i++){
                result += pow(10, i) * s[i];
            }
            return result;
        } else {
            x *= -1;
            result = reverse(x);
            result *= -1;
            return result;
        }
    }
}

int main() {
    int to_reverse;
    scanf("%d", &to_reverse);
    printf("reverse %d = %d", to_reverse, reverse(to_reverse));
    return 0;
}