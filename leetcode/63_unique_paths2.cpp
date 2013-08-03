class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > &grid = obstacleGrid;
        vector<vector<int> > count_grid;
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        for (int i = 0; i < num_rows; i++) {
            vector<int> count_line(num_cols, 0);
            count_grid.push_back(count_line);
        }
        
        for (int i = num_rows-1; i >= 0; i--) {
            for (int j = num_cols-1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    count_grid[i][j] = 0;
                } else {
                    bool is_end = true;
                    int down = 0, right = 0;
                    if (j < num_cols-1) {
                        right = count_grid[i][j+1];
                        is_end = false;
                    }
                    if (i < num_rows-1) {
                        down = count_grid[i+1][j];
                        is_end = false;
                    }
                    count_grid[i][j] = is_end ? 1 : right + down;
                }
            }
        }
        
        return count_grid[0][0];
    }
};
