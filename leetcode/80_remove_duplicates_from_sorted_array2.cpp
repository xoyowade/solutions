class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) {
            return n;
        }
        int end = 1;
        int cur = A[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] == cur) {
                if (++count <= 2) {
                    A[end++] = A[i];
                }
            } else {
                cur = A[i];
                count = 1;
                A[end++] = A[i];
            }
        }
        
        return end;
    }
};
