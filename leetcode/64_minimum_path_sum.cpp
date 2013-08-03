struct Path {
    int len;
    bool right;
    void Set(int _len, bool _right) {
        len = _len;
        right = _right;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        vector<vector<Path> > path_grid;
        for (int i = 0; i < num_rows; i++) {
            path_grid.push_back(vector<Path>(num_cols, Path()));
        }
        
        for (int i = num_rows-1; i >= 0; i--) {
            for (int j = num_cols - 1; j >= 0; j--) {
                int right = INT_MAX, down = INT_MAX;
                if (j < num_cols-1) {
                    right = path_grid[i][j+1].len;
                }
                if (i < num_rows-1) {
                    down = path_grid[i+1][j].len;
                }
                if (right < down) {
                    path_grid[i][j].Set(right + grid[i][j], true);
                } else if (down < INT_MAX) {
                    path_grid[i][j].Set(down + grid[i][j], false);
                } else {
                    path_grid[i][j].len = grid[i][j];
                }
            }
        }
        
        return path_grid[0][0].len;
    }
};
