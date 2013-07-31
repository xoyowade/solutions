class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > matrix;
        for (int i = 0; i < n; i++) {
            vector<int> line(n, 0);
            matrix.push_back(line);
        }
        int x = 0;
        int y = -1;
        int num = 1;
        int end = n*n;
        do {
            
            y++;
            while (y < n && matrix[x][y] == 0) {
                matrix[x][y] = num++;
                y++;
            }
            y--;
            
            x++;
            while (x < n && matrix[x][y] == 0) {
                matrix[x][y] = num++;
                x++;
            }
            x--;
            
            y--;
            while (y >= 0 && matrix[x][y] == 0) {
                matrix[x][y] = num++;
                y--;
            }
            y++;
            
            x--;
            while (x >= 0 && matrix[x][y] == 0) {
                matrix[x][y] = num++;
                x--;
            }
            x++;
        } while (num <= end);
        
        return matrix;
    }
};
