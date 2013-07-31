class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 0;
        while (c+A[c] < n-1) {
            int max_reach = 0;
            for (int i = c; i <= A[c]+c; i++) {
                if (A[i]+i > A[max_reach]+max_reach) {
                    max_reach = i;
                }
            }
            if (max_reach == c) {
                return false;
            }
            c = max_reach;
        }
        return true;
    }
};
