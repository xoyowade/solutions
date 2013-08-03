class Solution {
public:
    void searchRow(vector<vector<int> > &matrix, int target, bool *found, int *row) {
        int l = 0;
        int r = matrix.size()-1;
        while (l < r) {
            int mid = (l+r)/2;
            int diff = matrix[mid][0] - target;
            if (diff == 0) {
                *row = mid;
                *found = true;
                return;
            } else if (diff > 0) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        *row = l;
        *found = false;
        return;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) {
            return false;
        }
        bool found = false;
        int row = 0;
        searchRow(matrix, target, &found, &row);
        if (found) {
            return true;
        }
        if (matrix[row][0] > target) {
            if (row == 0) {
                return false;
            } else {
                row--;   
            }
        }
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};
