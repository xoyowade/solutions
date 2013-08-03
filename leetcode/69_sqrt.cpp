class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x == 0 || x == 1) {
            return x;
        }
        
        int l = 1;
        int r = x/2;
        int s = r;
        while (true) {
            int times = x/s;
            if (times == s) {
                return s;
            } else if (s > times) {
                r = s;
                s = (l+r)/2;
                if (r == s) {
                    return s;
                }
            } else {
                l = s;
                s = (l+r)/2;
                if (l == s) {
                    return s;
                }
            }
        }
    }
};
