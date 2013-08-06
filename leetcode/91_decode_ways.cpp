class Solution {
public:
    int oneDigit(const vector<int> &nums, const string &s, int i) {
        int num = s[i]-'0';
        if (1 <= num && num <= 9) {
            return (i+1 < nums.size()) ? nums[i+1] : 1;
        }
        return 0;
    }
    int twoDigits(const vector<int> &nums, const string &s, int i) {
        int num = atoi(s.substr(i, 2).c_str());
        if (10 <= num && num <= 26) {
            return (i+2 < nums.size()) ? nums[i+2] : 1;
        }
        return 0;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) {
            return 0;
        }
        vector<int> nums(s.length(), 0);
        for (int i = s.length()-1; i >= 0; i--) {
            nums[i] = oneDigit(nums, s, i) + twoDigits(nums, s, i);
        }
        
        return nums[0];
    }
};
