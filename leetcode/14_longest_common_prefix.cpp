class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }
        int min = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].length();
            if (len < min) {
                min = len;
            }
        }
        string s;
        for (int i = 0; i < min; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return s;
                }
            }
            s.push_back(c);
        }
        return s;
    }
};
