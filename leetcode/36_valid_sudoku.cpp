#include <math.h> 

class Solution {
public:
    bool isValid(vector<char> &set) {
        static bool nums[9];
        memset(nums, 0, 9);
        for (int i = 0; i < set.size(); i++) {
            if (set[i] != '.') {
                int index = set[i] - '1';
                if (nums[index]) {
                    return false;
                }
                nums[index] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int size = board.size();
        for (int i = 0; i < size; i++) {
            if (!isValid(board[i])) {
                return false;
            }
        }
        
        for (int i = 0; i < size; i++) {
            vector<char> set;
            for (int j = 0; j < size; j++) {
                set.push_back(board[j][i]);
            }
            if (!isValid(set)) {
                return false;
            }
        }
        
        const int subsize = sqrt(size);
        for (int col = 0; col < subsize; col++) {
            for (int row = 0; row < subsize; row++) {
                vector<char> set;
                for (int i = col*subsize; i < col*subsize+subsize; i++) {
                    for (int j = row*subsize; j < row*subsize+subsize; j++) {
                        set.push_back(board[i][j]);
                    }
                }
                if (!isValid(set)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
