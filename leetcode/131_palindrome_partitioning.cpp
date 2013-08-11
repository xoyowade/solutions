class Solution {
public:
    struct Range {
        int l;
        int r;
        Range(int _l, int _r) {
            l = _l;
            r = _r;
        }
    };
    void buildRes(string &s, vector<vector<Range> > &palindromes, int l, vector<int> &ends) {
        if (l == s.length()) {
            int l = 0;
            vector<string> part;
            for (int i = 0; i < ends.size(); i++) {
                int r = ends[i];
                part.push_back(s.substr(l, r-l+1));
                l = r+1;
            }
            res.push_back(part);
            return;
        }
        const vector<Range> &ranges = palindromes[l];
        for (int i = 0; i < ranges.size(); i++) {
            const Range &range = ranges[i];
            ends.push_back(range.r);
            buildRes(s, palindromes, range.r+1, ends);
            ends.pop_back();
        }
    }
    void findPalindromes(string &s, int l, int r, vector<vector<Range> > &palindromes) {
        while (0 <= l && r < s.length()) {
            if (s[l] == s[r]) {
                palindromes[l].push_back(Range(l, r));
            } else {
                break;
            }
            l--;
            r++;
        }
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<Range> > palindromes(s.length(), vector<Range>());
        for (int i = 0; i < s.length(); i++) {
            // no center
            findPalindromes(s, i, i+1, palindromes);
            findPalindromes(s, i, i, palindromes);
        }
        
        res.clear();
        vector<int> ends;
        buildRes(s, palindromes, 0, ends);
        return res;
    }
    vector<vector<string> > res;
};
