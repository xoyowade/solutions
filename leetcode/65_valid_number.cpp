class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool has_dot = false, has_e = false, has_sign = false, 
             has_digit = false, has_num = false, is_open = false;
        while (*s) {
            if (!has_num && '0' <= *s && *s <= '9') {
                has_digit = true;
                s++;
                is_open = true;
            } else if (!has_num && !is_open && !has_digit && !has_sign && (*s == '+' || *s == '-')) {
                is_open = true;
                has_sign = true;
                s++;
            } else if (!has_num && !has_e && !has_dot && *s == '.') {
                is_open = true;
                has_dot = true;
                s++;
            } else if (has_digit && !has_e && *s == 'e') {
                has_e = true;
                has_digit = false;
                has_sign = false;
                is_open = false;
                s++;
            } else if (*s == ' ') {
                has_num |= (is_open || has_e);
                is_open = false;
                s++;
            } else {
                return false;
            }
        }
        
        return has_digit;
    }
};
