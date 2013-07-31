class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        int x = 0, y = -1;
        bool move = false;
        do {
            move = false;
            // right
            y++;
            while (y < num_cols && matrix[x][y] != INT_MIN) {
                res.push_back(matrix[x][y]);
                matrix[x][y] = INT_MIN;
                move = true;
                y++;
            }
            y--;
            
            // down
            x++;
            while (x < num_rows && matrix[x][y] != INT_MIN) {
                res.push_back(matrix[x][y]);
                matrix[x][y] = INT_MIN;
                move = true;
                x++;
            }
            x--;
            
            // left
            y--;
            while (y >= 0 && matrix[x][y] != INT_MIN) {
                res.push_back(matrix[x][y]);
                matrix[x][y] = INT_MIN;
                move = true;
                y--;
            }
            y++;
            
            // up
            x--;
            while (x >= 0 && matrix[x][y] != INT_MIN) {
                res.push_back(matrix[x][y]);
                matrix[x][y] = INT_MIN;
                move = true;
                x--;
            }
            x++;
            
        } while (move);
        
        return res;
    }
};
