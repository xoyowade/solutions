iclass Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = matrix.size();
        for (int i = 0; i < size/2; i++) {
            for (int j = 0; j < size; j++) {
                swap(matrix[j][i], matrix[j][size-1-i]);
            }
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size-1-i; j++) {
                swap(matrix[j][i], matrix[size-1-i][size-1-j]);
            }
        }
    }
};
