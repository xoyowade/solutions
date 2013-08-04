class Solution {
public:
    bool search(int A[], int n, int start, int target) {
        int end = (start + n - 1) % n;
        
        int s = start;
        int e = end;
        while (s != e) {
            int mid = (s+((e-s+n)%n/2))%n;
            int diff = A[mid] - target;
            if (diff == 0) {
                return true;
            } else if (diff < 0) {
                s = (mid+1)%n;   
            } else {
                e = mid;
            }
        }
        return A[s] == target;
    }
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return false;
        }
        int start = 1;
        while (start < n) {
            if (A[start] < A[start-1]) {
                break;   
            }
            start++;
        }
        if (start == n) {
            start = 0;
        }
        
        return search(A, n, start, target);
    }
};
