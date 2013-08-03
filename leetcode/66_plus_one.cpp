class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 1;
        vector<int> new_digits;
        for (int i = digits.size()-1; i >= 0; i--) {
            int sum = digits[i]+carry;
            carry = sum/10;
            new_digits.push_back(sum%10);
        }
        if (carry > 0) {
            new_digits.push_back(carry);
        }
        for (int i = 0; i < new_digits.size()/2; i++) {
            swap(new_digits[i], new_digits[new_digits.size()-i-1]);
        }
        return new_digits;
    }
};
