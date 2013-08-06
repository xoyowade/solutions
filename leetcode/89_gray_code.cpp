class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            vector<int> res = {0};
            return res;
        }
        if (n == 1) {
            vector<int> res = {0, 1};
            return res;
        }
        
        const vector<int> &sub = grayCode(n-1);
        vector<int> res;
        res.insert(res.begin(), sub.begin(), sub.end());
        int b = (1<<(n-1));
        for (int i = sub.size()-1; i >= 0; i--) {
            res.push_back(sub[i]|b);
        }
        
        return res;
    }
};
