#include <stdlib.h>

class Solution {
public:
    bool valid(int x, int y) {
        for (int i = 0; i < x; i++) {
            if (abs(i - x) == abs(cols[i] - y)) {
                return false;
            }
        }
        return true;
    }
    void search(int line, int max) {
        if (line == max) {
            count++;
            return;
        }
        for (int i = 0; i < max; i++) {
            if (available[i] && valid(line, i)) {
                available[i] = false;
                cols[line] = i;
                search(line+1, max);
                available[i] = true;
            }
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        count = 0;
        cols.clear();
        available.clear();
        for (int i = 0; i < n; i++) {
            cols.push_back(-1);
            available.push_back(true);
        }
        
        search(0, n);
        
        return count;
    }
private:
    int count;
    vector<int> cols;
    vector<bool> available;
};
