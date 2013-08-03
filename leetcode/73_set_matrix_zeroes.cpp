class Solution {
public:
    void setZero(vector<vector<int> > &matrix, int x, int y) {
        for (int i = 0; i < matrix.size(); i++) {
            if (i != x && matrix[i][y] != 0) {
                matrix[i][y] = 0;
                setZero(matrix, i, y);
            }
        }
        for (int j = 0; j < matrix[x].size(); j++) {
            if (j != y && matrix[x][j] != 0) {
                matrix[x][j] = 0;
                setZero(matrix, x, j);
            }
        }
    }
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // save
        bool row_zero = false;
        bool col_zero = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                col_zero = true;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                row_zero = true;
            }
        }
        
        // mark
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        // set
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row_zero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if (col_zero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
