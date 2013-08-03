class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) {
            return n;
        }
        int p1 = 1;
        int p2 = 2;
        int steps;
        int i = 3;
        while (i <= n) {
            steps = p1 + p2;
            p1 = p2;
            p2 = steps;
            i++;
        }
        return steps;
    }
};
