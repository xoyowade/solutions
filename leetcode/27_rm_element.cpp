class Solution {
public:
    void swap(int A[], int i1, int i2) {
        int tmp = A[i1];
        A[i1] = A[i2];
        A[i2] = tmp;
    }
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = n;
        for (int i = 0; i < len; i++) {
            if (A[i] == elem) {
                swap(A, i, len-1);
                i--;
                len--;
            }
        }
        return len;
    }
};
