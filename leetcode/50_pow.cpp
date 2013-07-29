class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 1;
        }
        
        double sqrt = pow(x, n/2);
        
        if (n % 2 == 0) {
            return sqrt*sqrt;
        } else if (n > 0) {
            return sqrt*sqrt*x;
        } else {
            return sqrt*sqrt/x;
        }
    }
};
