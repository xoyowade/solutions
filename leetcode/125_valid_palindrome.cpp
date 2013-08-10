class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) {
            return true;
        }
        
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        
        int l = 0;
        int r = s.length()-1;
        while (l != r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (!isalnum(s[l]) || !isalnum(s[r])) {
                return true;
            }
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
