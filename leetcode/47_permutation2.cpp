class Solution {
public:
    void dfs(int step, const vector<int> &num) {
        if (num.size() == step) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < num.size(); i++) {
            if (!used[i]) {
                if (i > 0 && num[i] == num[i-1] && !used[i-1]) {
                    continue;
                }
                used[i] = true;
                path.push_back(num[i]);
                dfs(step+1, num);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        used.assign(num.size(), false);
        res.clear();
        dfs(0, num);

        return res;
    }
private:
    vector<int> path;
    vector<bool> used;
    vector<vector<int> > res;
};
