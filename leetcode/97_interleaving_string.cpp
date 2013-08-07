class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1+len2 != len3) {
            return false;
        }
        if (s3.empty()) {
            return true;
        }
        
        vector<vector<bool> > res;
        for (int i = 0; i <= len1; i++) {
            vector<bool> v(len2+1, false);
            res.push_back(v);
        }
        
        res[0][0] = true;
        for (int i = 1; i <= len2; i++) {
            res[0][i] = res[0][i-1] && s2[len2-i] == s3[len3-i];
        }
        for (int i = 1; i <= len1; i++) {
            res[i][0] = res[i-1][0] && s1[len1-i] == s3[len3-i];
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                res[i][j] = (res[i-1][j] && s1[len1-i] == s3[len3-i-j]) ||
                            (res[i][j-1] && s2[len2-j] == s3[len3-i-j]);
            }
        }
        return res[len1][len2];
    }
};
