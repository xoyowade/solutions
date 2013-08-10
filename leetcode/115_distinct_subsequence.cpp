class Solution {
public:
    void numDistinct_dfs(string &S, int s1, string &T, int s2) {
        if (s2 == T.length()) {
            count++;
            return;
        }
        if (s1 == S.length()) {
            return;
        }
        
        int len = T.length()-s2;
        for (int i = s1; i+len <= S.length(); i++) {
            if (S[i] == T[s2]) {
                numDistinct_dfs(S, i+1, T, s2+1);
            }
        }
    }
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len_s = S.length();
        int len_t = T.length();
        vector<vector<int> > res;
        // init
        for (int i = 0; i <= len_t; i++) {
            res.push_back(vector<int>(len_s+1, 0));
        }
        // empty T
        res[0][0] = 1;
        // dp
        for (int i = 1; i <= len_t; i++) {
            for (int j = i; j <= len_s-len_t+i; j++) {
                int num = 0;
                if (T[i-1] == S[j-1]) {
                    for (int k = i-1; k <= j-1; k++) {
                        num += res[i-1][k];
                    }
                }
                res[i][j] = num;
            }
        }
        
        // total
        int total = 0;
        for (int i = len_t; i <= len_s; i++) {
            total += res[len_t][i];
        }
        return total;
    }
    
    int count;
};
