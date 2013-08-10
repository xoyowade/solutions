class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        for (int i = 0; i < numRows; i++) {
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j < i; j++) {
                line.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            if (i > 0) {
                line.push_back(1);
            }
            res.push_back(line);
        }
        
        return res;
    }
};
