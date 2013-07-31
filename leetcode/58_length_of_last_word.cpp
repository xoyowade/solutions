class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur_len = 0;
        int last_len = 0;
        bool inword = false;
        while (*s) {
            if (*s != ' ') {
                cur_len++;
                inword = true;
            } else {
                if (inword) {
                    last_len = cur_len;
                    cur_len = 0;
                    inword = false;
                }
            }
            s++;
        }
        return cur_len != 0 ? cur_len : last_len;
    }
};
