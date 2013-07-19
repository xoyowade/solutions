class Solution {
public:
    void removeItem(int A[], int n, int p) {
        for (int i = p; i < n-1; i++) {
            A[i] = A[i+1];
        }
    }
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = n;
        for (int i = 0; i < len-1; i++) {
            if (A[i] == A[i+1]) {
                removeItem(A, len, i);
                len--;
                i--;
            }
        }
        return len;
    }
};
