class Solution {
public:
    vector<vector<int> > findSubsets(vector<int> &S) {
        vector<vector<int> > res;
        
        if (S.empty()) {
            vector<int> empty_subset;
            res.push_back(empty_subset);
            return res;
        }
        
        int c = S.back();
        S.pop_back();
        const vector<vector<int> > &sub_res = findSubsets(S);
        for (int i = 0; i < sub_res.size(); i++) {
            vector<int> subset = sub_res[i];
            res.push_back(subset);
            subset.push_back(c);
            res.push_back(subset);
        }
        
        return res;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        
        return findSubsets(S);
        
    }
};
