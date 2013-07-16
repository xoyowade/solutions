class Solution {
public:
    vector<string> combine(string digits,  vector<string>& mapping) {
        vector<string> result;
        char c = digits.back();
        string& chars = mapping[c-'0'];
        if (digits.length() == 1) {
            for (int i = 0; i < chars.length(); i++) {
                result.push_back(string(1, chars[i]));
            }
            return result;
        }
        digits.pop_back();
        vector<string> before = combine(digits, mapping);
        for (int i = 0; i < chars.length(); i++) {
            for (int j = 0; j < before.size(); j++) {
                result.push_back(before[j]+chars[i]);
            }
        }
        return result;
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (digits.length() < 1) {
            vector<string> result;
            result.push_back("");
            return result;
        }
        vector<string> mapping = {"", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
        };
        return combine(digits, mapping);
    }
};
