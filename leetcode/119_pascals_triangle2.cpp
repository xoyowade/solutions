class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> prev(rowIndex+1, 1);
        vector<int> cur = prev;

        for (int i = 1; i <= rowIndex; i++) {
            cur.swap(prev);
            cur[0] = 1;
            for (int j = 1; j < i; j++) {
                cur[j] = prev[j-1] + prev[j];
            }
            cur[i] = 1;
        }
        
        return cur;
    }
};
