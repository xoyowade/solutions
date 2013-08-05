class Solution {
public:
    
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return;
        }
        
        int i = m-1;
        int j = n-1;
        int last = m+n-1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[last--] = A[i--];
            } else {
                A[last--] = B[j--];
            }
        }
        
        memcpy(A+i+1, B, (j+1)*sizeof(int));
    }
};
