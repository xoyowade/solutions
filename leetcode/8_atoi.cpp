// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!str || !(*str)) return 0;
        bool sign = true;
        bool skip = false;
        do {
            if (*str == '+') {
                skip = true;
                break;
            } else if (*str == '-') {
                skip = true;
                sign = false;
                break;
            } else if ('0' <= *str && *str <= '9') {
                break;
            } else if ('A' <= *str && *str <= 'z') {
                return 0;
            }
            str++;
        } while (*str);
        if (skip) {
            str++;
        }
        // skip 0s
        while (*str && *str == '0') {
            str++;
        }
        
        vector<char> digits;
        while(*str) {
            if ('0' <= *str && *str <= '9') {
                digits.push_back(*str);
                str++;
            } else {
                break;
            }
        }
        
        // calculate
        int ret = 0, base = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int num = (digits[i]-'0');
            int add = num * base;
            if (add != 0 && add / num != base) {
                return sign ? INT_MAX : INT_MIN;
            }
            // printf("+%d(%d*%d)\n", add, (digits[i]-'0'), base);
            if (ret > INT_MAX - add) {
                return sign ? INT_MAX : INT_MIN;
            }
            ret += add;
            // printf("%d\n", ret);
            if (i > 0 && INT_MAX/base < 10) {
                return sign ? INT_MAX : INT_MIN;
            }
            base *= 10;
        }
        return sign ? ret : (0-ret);
    }
};

int main() {
    // Start typing your code here...
    Solution s;
    cout << s.atoi("    10522545459") << endl;
    
    return 0;
}
