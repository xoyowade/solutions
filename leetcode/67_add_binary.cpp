class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.length() == 0) {
            return b;
        }
        if (b.length() == 0) {
            return a;
        }
        vector<int> num;
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        while (i >=0 && j >= 0) {
            int sum = a[i]-'0' + b[j]-'0' + carry;
            carry = sum/2;
            num.push_back(sum%2);
            i--;
            j--;
        }
        while (i >= 0) {
            int sum = a[i]-'0' + carry;
            carry = sum/2;
            num.push_back(sum%2);
            i--;
        }
        while (j >= 0) {
            int sum = b[j]-'0' + carry;
            carry = sum/2;
            num.push_back(sum%2);
            j--;
        }
        if (carry > 0) {
            num.push_back(carry);
        }
        
        string s;
        for (int i = num.size()-1; i >= 0; i--) {
            s.push_back(num[i]+'0');
        }
        
        return s;
    }
};
