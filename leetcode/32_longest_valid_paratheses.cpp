class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> opens;
        int start = s.length();
        int max_len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                opens.push_back(i);
                continue;
            }
            if (opens.empty()) {
                start = s.length();
            } else {
                start = min(opens.back(), start);
                opens.pop_back();
                // handle "(()"
                int len;
                if (opens.empty()) {
                    len = i - start + 1;
                } else {
                    len = i - opens.back();
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
