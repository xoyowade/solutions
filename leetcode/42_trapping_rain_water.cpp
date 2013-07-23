// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = 0;
        int total = 0;
        
        do {
            // find left
            while (l < n-2 && A[l] <= A[l+1]) {
                l++;
            }
            if (l == n-2) {
                return total;
            }
            // find right
            int max_less_than = l+2;
            for (r = l+2; r < n; r++) {
                if (A[r] >= A[l]) {
                    break;
                } else if (A[r] > A[max_less_than]) {
                    max_less_than = r;
                }
            }
            if (r >= n) {
                if (max_less_than < n && A[max_less_than] > 0) {
                    r = max_less_than;
                } else {
                    return total;
                }
            }
            
            printf("compute [%d, %d] - [%d, %d]\n", l, r, A[l], A[r]);
            // finish a trap
            int high = min(A[l], A[r]);
            for (int i = l+1; i <= r-1; i++) {
                if (A[i] < high) {
                    total += high - A[i];
                }
            }
            l = r;
        } while (l < n && r < n);
        
        return total;
    }
};

int main() {
    // Start typing your code here...
    vector<int> num = {8,2,8,9,0,1,7,7,9};
    Solution s;
    cout << s.trap(num.data(), num.size()) << endl;

    return 0;
}
