// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x == 0) return x;
        if (x < 0) {
            return 0 - reverse(0 - x);
        }
        int num_digits = (int)log10((int)x) + 1;
        int* digits = new int[num_digits];
        int n = 0;
        do {
            digits[n++] = x%10;
            x = x/10;
        } while(x != 0);
        int ret = 0, base = 1, start;
        for (start = 0; start < num_digits; start++) {
            if (digits[start] != 0) break;
        }
        for (int i = num_digits-1; i >= start; i--) {
            ret += digits[i] * base;
            base *= 10;
        }
        delete[] digits;
        return ret;
    }
};

int main() {
    // Start typing your code here...
    Solution s;
    cout << s.reverse(123) << endl;
    return 0;
}
