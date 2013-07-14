class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() <= 1) {
            return s;
        }
        int max_len = 0;
        int max_from = 0;
        for (int i = 1; i < s.length(); i++) {
            int len = 1;
            int extend = min(i + 1, (int)(s.length() - i));
            int step;
            // odd
            for (step = 1; step < extend; step++) {
                if (s[i-step] == s[i+step]) {
                    len += 2;
                } else {
                    break;
                }
            }
            if (len > max_len) {
                max_len = len;
                max_from = i - (step-1);
            }
            // even
            if (s[i-1] == s[i]) {
                len = 2;
                extend = min(i, (int)(s.length() - i));
                for (step = 1; step < extend; step++) {
                    if (s[i-1-step] == s[i+step]) {
                        len += 2;
                    } else {
                        break;
                    }
                }
                if (len > max_len) {
                    max_len = len;
                    max_from = i - 1 - (step-1);
                }
            }
        }
        return s.substr(max_from, max_len);
    }
};
