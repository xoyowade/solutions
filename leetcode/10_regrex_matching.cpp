// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (!s || !p) return false;
		// printf("test %s for %s\n", s, p);
        if (!*s && !*p) return true;
        if (!*p) return false;
        
        if (*(p+1) == '*') {
            while (*s) {
                if (isMatch(s, p+2)) {
                    return true;
                }
                if (*p != '.' && *p != *s) {
                    return false;
                }
                s++;
            }
            return isMatch(s, p+2);
        }
        if (!*s) {
            return false;
        }
        if (*p == '.') {
            return isMatch(s+1, p+1);
        } else {
            if (*s == *p) {
                return isMatch(s+1, p+1);
            }
            return false;
        }
    }
};

int main() {
    // Start typing your code here...
    Solution s;
    cout << s.isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*") << endl;
    //cout << s.isMatch("", "c*.*a*") << endl;
    
    return 0;
}
