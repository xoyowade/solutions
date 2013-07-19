class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len_haystack = 0;
        char *str = haystack;
        while (*str) {
            str++;
            len_haystack++;
        }
        int len_needle = 0;
        char *pattern = needle;
        while (*pattern) {
            pattern++;
            len_needle++;
        }
        while (*haystack && *needle && len_haystack >= len_needle) {
            char* cur = haystack;
            char *pattern = needle;
            while (*pattern && *cur == *pattern) {
                cur++;
                pattern++;
            }
            if (!*pattern) {
                return haystack;
            }
            haystack++;
            len_haystack--;
        }
        if (!*needle) {
            return haystack;
        }
        return NULL;
    }
};

