class Solution {
public:
    bool isScramble(string &s1, string &s2, int p1, int l1, int p2, int l2) {
        if (l1 != l2) {
            return false;
        }
        // check chars
        vector<int> chars(26, 0);
        for (int i = p1; i < p1+l1; i++) {
            chars[s1[i]-'a']++;
        }
        for (int i = p2; i < p2+l2; i++) {
            if (chars[s2[i]-'a']-- == 0) {
                return false;
            }
        }
        
        if (l1 == 1) {
            return true;
        }
        
        for (int i = 1; i < l1; i++) {
            bool res =  (isScramble(s1, s2, p1, i, p2, i) && 
                        isScramble(s1, s2, p1+i, l1-i, p2+i, l2-i)) ||
                    (isScramble(s1, s2, p1, i, p2+l2-i, i) && 
                        isScramble(s1, s2, p1+i, l1-i, p2, l2-i));
            if (res) {
                return true;
            }
            
        }
        
        return false;
    }
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() == 0) {
            return true;
        }
        
        return isScramble(s1, s2, 0, s1.length(), 0, s2.length());
    }
};
