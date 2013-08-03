class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p0 = 0;
        int p2 = n-1;
        for (int i = 0; i < n && i <= p2; i++) {
            if (A[i] == 0) {
                swap(A[i], A[p0]);
                p0++;
            } else if (A[i] == 2) {
                swap(A[i], A[p2]);
                p2--;
                i--;
            }
        }
    }
};
