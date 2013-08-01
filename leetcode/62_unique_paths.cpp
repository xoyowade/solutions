class Solution {
public:

    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1 || m == 1) {
            return 1;
        }
        int big = max(m, n);
        int small = min(m, n);
        
        int res = 1;
        int i = m+n-2;
        int j = 1;
        while (i >= big  && j <= small-1) {
            if (res >= j && res % j == 0) {
                res /= j;
                j++;
            } else {
                res *= i;
                i--;
            }
        }
        
        while (i >= big) {
            res *= i;
            i--;
        }
        
        while (j <= small-1) {
            res /= j;
            j++;
        }
        
        
        return res;
    }
};
