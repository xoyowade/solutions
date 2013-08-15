class Solution {
public:
    string intToRoman(int num) {
        string roman;
        
        for (int i = 0; i < sizeof(values)/sizeof(int); i++) {
            while (num >= values[i]) {
                roman += symbols[i];
                num -= values[i];
            }
        }
        return roman;
    }
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};
