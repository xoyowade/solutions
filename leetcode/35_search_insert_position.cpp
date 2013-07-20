class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = n-1;
        while (l != r) {
            int mid = l + (r-l)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (A[l] < target) {
            return l+1;
        }
        return l;
    }
};
