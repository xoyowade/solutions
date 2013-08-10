class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int rows = triangle.size();
        vector<int> cur = triangle[rows-1];
        vector<int> prev = cur;
        for (int i = rows-2; i >= 0; i--) {
            cur.swap(prev);
            for (int j = 0; j <= i; j++) {
                cur[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
        }
        return cur[0];
    }
};
