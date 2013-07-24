class Solution {
public:
    int multiply(const int *num, int n, int mul, int *res) {
        if (mul == 0) {
            return 0;
        }
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int sum = num[i]*mul + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            res[n] = carry;
            return n+1;
        } else {
            return n;
        }
    }
    void add(const int *add, int n, int* res) {
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int sum = res[i] + add[i] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            int sum = res[n] + carry;
            res[n] = sum % 10;
            if (sum >= 10) {
                res[n+1] = sum / 10;
            }
        }
    }
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.length();
        int len2 = num2.length();
        int *digits1 = new int[len1];
        int *digits2 = new int[len2];
        int *res = new int[len1+len2];
        memset(res, 0, sizeof(int)*(len1+len2));
        int *partial_res = new int[len1+1];
        
        // parse
        for (int i = len1-1; i >= 0;  i--) {
            digits1[len1-1-i] = num1[i] - '0';
        }
        for (int i = len2-1; i >= 0;  i--) {
            digits2[len2-1-i] = num2[i] - '0';
        }
        
        // cal
        for (int i = 0; i < len2; i++) {
            memset(partial_res, 0, sizeof(int)*(len1+1));
            int num_digits = multiply(digits1, len1, digits2[i], partial_res);
            if (num_digits == 0) {
                continue;
            } else {
                add(partial_res, num_digits, res+i);
            }
        }
        
        // dump
        string str;
        int start_index = len1+len2-1;
        while (start_index >= 0 && res[start_index] == 0) {
            start_index--;
        }
        for (int i = start_index; i >= 0; i--) {
            str += res[i]+'0';
        }
        if (str.length() == 0) {
            str = "0";
        }
        delete[] digits1;
        delete[] digits2;
        delete[] res;
        delete[] partial_res;
        
        return str;
    }
};
