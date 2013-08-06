class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1 || n == 0) {
            return 1;
        }
        int num = 0;
        for (int i = 1; i <= n; i++) {
            num += numTrees(i-1) * numTrees(n-i);
        }
        
        return num;
    }
};
