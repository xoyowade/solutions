class Solution {
public:
    bool isValid(string &s, int start, int offset) {
        if (start + offset < s.length()) {
            int num = atoi(s.substr(start, offset+1).c_str());
            switch (offset) {
                case 0:
                    return true;
                case 1:
                    return 10 <= num && num <= 99;
                case 2:
                    return 100 <= num && num <= 255;
            }
        }
        return false;
    }
    void restore(string &s, int start, int n) {
        if (n == 3) {
            if (start >= s.length()) {
                return;
            }
            int offset = s.length() - start - 1;
            if (!isValid(s, start, offset)) {
                return;
            }
            string ns = s;
            for (int i = 0; i < 3; i++) {
                ns.insert(pos[i]+i, 1, '.');
            }
            res.push_back(ns);
            return;
        }
        if (isValid(s, start, 0)) {
            pos[n] = start+1;
            restore(s, start+1, n+1);
        }
        if (isValid(s, start, 1)) {
            pos[n] = start+2;
            restore(s, start+2, n+1);
        }
        if (isValid(s, start, 2)) {
            pos[n] = start+3;
            restore(s, start+3, n+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        
        restore(s, 0, 0);
        
        return res;
    }
    
    vector<string> res;
    int pos[3];
};
