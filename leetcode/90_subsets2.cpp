class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        res.push_back(vector<int>());
        if (S.empty()) {
            return res;
        }
        sort(S.begin(), S.end());
        
        int start = 0;
        for (int i = 0; i < S.size(); i++) {
            int size = res.size();
            for (int j = start; j < size; j++) {
                vector<int> subset = res[j];
                subset.push_back(S[i]);
                res.push_back(subset);
            }
            if (i < S.size()-1 && S[i] == S[i+1]) {
                start = size;
            } else {
                start = 0;
            }
        }
        
        return res;
    }
};
