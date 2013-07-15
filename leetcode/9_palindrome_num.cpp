#include <math.h>

class Solution {
public:
    int digit(int x, int base) {
        return (x/base)%10;
    }
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int num_digits = log10(x) + 1;
        for (int i = 0; i < num_digits/2; i++) {
            int base1 = (double)pow(10, i);
            int base2 = (double)pow(10, num_digits - i - 1);
            if (digit(x, base1) != digit(x, base2)) {
                return false;
            }
        }
        return true;
    }
};
