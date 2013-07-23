class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++) {
            if (A[i]-1 != i) {
                if (0 < A[i] && A[i] < n) {
                    // handle [1, 1]
                    if (A[i] != A[A[i]-1]) {
                        swap (A[i], A[A[i]-1]);
                        i--;
                    }
                }
            }
        }
        int max_positive = 0;
        for (int i = 0; i < n; i++) {
            if (A[i]-1 != i) {
                return i+1;
            } else if (A[i] > 0) {
                max_positive = max(max_positive, A[i]); 
            }
        }
        return max_positive+1;
    }
};
