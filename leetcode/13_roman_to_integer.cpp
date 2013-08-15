class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int val = 0;
        int pos = 0;
        
        for (int i = 0; i < sizeof(symbols)/sizeof(char*); i++) {
            while (s.compare(pos, strlen(symbols[i]), symbols[i]) == 0) {
                val += values[i];
                pos += strlen(symbols[i]);
            }
            if (pos >= s.length()) {
                break;
            }
        }
        
        return val;
    }
    
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};
