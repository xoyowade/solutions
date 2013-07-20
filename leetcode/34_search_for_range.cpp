class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        int r = n-1;
        while (l != r) {
            int mid = l + (r-l)/2;
            if (A[mid] == target) {
                int left = mid-1;
                while (left >= 0 && A[left] == target) {
                    left--;
                }
                left++;
                int right = mid+1;
                while (right < n && A[right] == target) {
                    right++;
                }
                right--;
                vector<int> v = {left, right};
                return v;
            } else if (A[mid] > target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        if (A[l] == target) {
            vector<int> v = {l, l};
            return v;
        }
        vector<int> v = {-1, -1};
        return v;
    }
};
