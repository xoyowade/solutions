class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0;
        int count = 0;
        while (start < n-1) {
            count++;
            int left = n-1 - start;
            if (A[start] >= left) {
                break;
            }
            int next_max = 0;
            int next = start;
            for (int i = A[start]; i >= 1; i--) {
                if (A[start+i]+i > next_max) {
                    next = start + i;
                    next_max = A[next]+i;
                }
            }
            start = next;
        }
        
        return count;
    }
};
