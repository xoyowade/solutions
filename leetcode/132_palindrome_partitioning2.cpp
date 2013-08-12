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
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<Range> > palindromes(s.length(), vector<Range>());
        
        for (int i = 0; i < s.length(); i++) {
            findPalindromes(s, i, i+1, palindromes);
            findPalindromes(s, i, i, palindromes);
        }
        
        queue<Range> q;
        vector<bool> visited(s.length(), false);
        for (int i = 0; i < palindromes[0].size(); i++) {
            q.push(palindromes[0][i]);
        }
        visited[0] = true;
        int count = q.size();
        int cut = 0;
        while (!q.empty()) {
            if (count == 0) {
                cut++;
                count = q.size();
            }
            count--;
            const Range &range = q.front();
            q.pop();
            if (range.r == s.length()-1) {
                return cut;
            }
            if (!visited[range.r+1]) {
                visited[range.r+1] = true;
                for (int i = 0; i < palindromes[range.r+1].size(); i++) {
                    q.push(palindromes[range.r+1][i]);
                }
            }
        }
        
        return cut;
    }
    
};
