class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int max_area = 0;
        int i = 0;
        while (i < height.size()) {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i++);
            } else {
                int t = s.top();
                s.pop();
                max_area = max(max_area, height[t] * (s.empty() ? i : (i-s.top()-1)));
            }
        }
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            max_area = max(max_area, height[t] * (s.empty() ? i : (i-s.top()-1)));
        }

        return max_area;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        
        vector<vector<int> > height;
        for (int i = 0; i < rows; i++) {
            vector<int> line;
            for (int j = 0; j < cols; j++) {
                line.push_back(matrix[i][j]=='0'?0:1);
            }
            height.push_back(line);
        }
    
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                height[i][j] += height[i][j]==1 ? height[i-1][j] : 0;
            }
        }
        
        int max_area = 0;
        for (int i = 0; i < rows; i++) {
            max_area = max(max_area, largestRectangleArea(height[i]));
        }
        
        return max_area;
    }
    int maximalRectangle_bruteforce(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        
        vector<vector<int> > height;
        for (int i = 0; i < rows; i++) {
            vector<int> line;
            for (int j = 0; j < cols; j++) {
                line.push_back(matrix[i][j]=='0'?0:1);
            }
            height.push_back(line);
        }
    
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                height[i][j] += height[i][j]==1 ? height[i-1][j] : 0;
            }
        }
        
        int max_area = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int h = height[i][j];
                for (int k = j; k < cols; k++) {
                    h = min(h, height[i][k]);
                    max_area = max(max_area, h*(k-j+1));
                }
            }
        }
        
        return max_area;
    }
};
