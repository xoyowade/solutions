// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (s.length() <= 1 || nRows <= 1) return s;
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int chars_per_cycle = (2*nRows-2);
        int num_cycles = s.length()/chars_per_cycle + 1;
        int columns_per_cycle = nRows - 1;
        const int num_columns = num_cycles * columns_per_cycle;
        char** table = new char*[nRows];
        for (int i = 0; i < nRows; i++) {
            table[i] = new char[num_columns];
            for (int j = 0; j < num_columns; j++) {
                table[i][j] = 0;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int cycle = i/chars_per_cycle;
            int offset = i%chars_per_cycle;
            int offset_col, offset_row;
            if (offset < nRows) {
                offset_col = 0;
                offset_row = offset;
            } else {
                offset_col = offset - nRows + 1;
                offset_row = 2*nRows - offset - 2;
            }
			// printf("table[%d][%d] = %c\n", offset_row, cycle*columns_per_cycle+offset_col, s[i]);
            table[offset_row][cycle*columns_per_cycle+offset_col] = s[i];
        }
        string ret;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < num_columns; j++) {
                if (table[i][j]) {
                    ret.push_back(table[i][j]);
                }
            }
            delete[] table[i];
        }
        delete[] table;
        return ret;
    }
};

int main() {
    // Start typing your code here...
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    
    return 0;
}
