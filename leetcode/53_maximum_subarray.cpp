class Solution {
public:
    int maxSubArrayDiv(int A[], int s, int t) {
        int n = t - s + 1;
        if (n == 1) {
            return A[s];
        }
        int mid = (s+t)/2;
        int max_left = maxSubArrayDiv(A, s, mid);
        int max_right = maxSubArrayDiv(A, mid+1, t);
        
        int max_mid_left = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= s; i--) {
            sum += A[i];
            if (sum > max_mid_left) {
                max_mid_left = sum;
            }
        }
        int max_mid_right = INT_MIN;
        sum = 0;
        for (int i = mid+1; i <= t; i++) {
            sum += A[i];
            if (sum > max_mid_right) {
                max_mid_right = sum;
            }
        }
        
        return max(max(max_left, max_right), max_mid_left+max_mid_right);
    }
    int maxSubArray(int A[], int n) {
        return maxSubArrayDiv(A, 0, n-1);
    }
    int maxSubArray_scan(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = INT_MIN;
        int max_so_far = INT_MIN;
        int max_now = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] >= 0) {
                min = 0;
            } else if (min < 0 && A[i] > min) {
                min = A[i];
            }
            int now = max_now + A[i];
            if (now > 0) {
                max_now = now;
            } else if (A[i] > 0) {
                max_now = A[i];
            } else {
                max_now = min;
            }
            if (max_now > max_so_far) {
                max_so_far = max_now;
            }
        }
        
        return max_so_far;
    }
};
