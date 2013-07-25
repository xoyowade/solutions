class Solution {
public:
    const char* nextNonStar(const char* p) {
        while (*p == '*') {
            p++;
        }
        return p;
    }
    bool isAllStar(const char* p) {
        p = nextNonStar(p);
        if (!*p) {
            return true;
        } else {
            return false;
        }
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!*s) {
            if (isAllStar(p)) {
                return true;
            } else {
                return false;
            }
        }
        if (!*p) {
            return false;
        }

        const char* store_p = NULL;
        const char* store_s = NULL;
        while (*s) {
            if (*p == '?' || *p == *s) {
                s++;
                p++;
            } else if (*p == '*') {
                p = nextNonStar(p);
                if (!*p) {
                    return true;
                }
                store_s = s;
                store_p = p;
            } else if (store_p) {
                s = ++store_s;
                p = store_p;
            } else {
                return false;
            }
        }

        if (!*s) {
            if (!*p || isAllStar(p)) {
                return true;
            }
        } else {
            return false;
        }
    }
};
