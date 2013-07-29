class Solution {
public:
    vector<int> insert(vector<int> v, int pos, int n) {
        v.insert(v.begin()+pos, n);
        
        return v;
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (num.size() == 0) {
            return res;
        }       
        if (num.size() == 1) {
            res.push_back(num);
            return res;
        }
        
        int n = num.back();
        num.pop_back();
        vector<vector<int> > subres = permute(num);
        for (int i = 0; i < subres.size(); i++) {
            vector<int> &permute = subres[i];
            for (int j = 0; j <= permute.size(); j++) {
                res.push_back(insert(permute, j, n));    
            }
        }
        
        return res;
    }
};
