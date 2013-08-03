class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign_dividend = dividend > 0;
        bool sign_divisor = divisor > 0;
        
        unsigned pos_dividend = sign_dividend ? dividend : -dividend;
        unsigned pos_divisor = sign_divisor ? divisor : -divisor;
        if (pos_dividend < pos_divisor) {
            return 0;
        } else if (pos_dividend == pos_divisor) {
            return sign_divisor ^ sign_dividend ? -1 : 1;
        } 
        
        int res = 0;
        while (pos_dividend >= pos_divisor) {
            unsigned part_res = 1;
            unsigned value = pos_divisor;
            while (value <= pos_dividend-value) {
                value <<= 1;
                part_res <<= 1;
            }
            if (value > pos_dividend) {
                value >> 1;
                part_res >>= 1;
            }
            pos_dividend -= value;
            res += part_res;
        }
        return sign_divisor ^ sign_dividend ? -res : res;
    }
};
