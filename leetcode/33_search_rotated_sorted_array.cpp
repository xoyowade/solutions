class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // find start
        int start = 0;
        for (int i = 0; i < n-1; i++) {
            if (A[i] > A[i+1]) {
                start = i+1;
            }
        }
        
        // binary search
        int l = start;
        int r = (start-1+n)%n;
        while (l != r) {
            int mid = (l + ((r-l+n)%n)/2)%n;
            int mid_val = A[mid];
            if (mid_val == target) {
                return mid;
            } else if (mid_val > target) {
                r = mid;
            } else {
                l = (mid+1)%n;
            }
        }
        if (A[l] == target) {
            return l;
        }
        return -1;
    }
};
