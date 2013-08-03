class Solution {
public:
    void dfs(int step, vector<bool> &available, int start) {
        if (step == 0) {
            res.push_back(comb);
        }
        for (int i = start; i < available.size(); i++) {
            if (available[i]) {
                available[i] = false;
                comb.push_back(i+1);
                dfs(step-1, available, i+1);
                comb.pop_back();
                available[i] = true;
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        comb.clear();
        vector<bool> available(n, true);
        dfs(k, available, 0);
        
        return res;
    }
    vector<vector<int> > res;
    vector<int> comb;
};
