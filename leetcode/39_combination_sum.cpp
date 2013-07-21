#include <algorithm>

class Solution {
public:
    struct comparator {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }
            return false;
        }
    } mycomparator;
    int search(const vector<int> &v, int target) {
        int l = 0;
        int r = v.size()-1;
        while (l != r) {
            int mid = l + (r - l)/2;
            if (v[mid] == target) {
                return mid;
            } else if (v[mid] > target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
    bool find(const vector<vector<int> > &vs, const vector<int> &v) {
        int l = 0;
        int r = vs.size()-1;
        while (l <= r) {
            int mid = (l+r)/2;
            bool res1 = mycomparator(vs[mid], v);
            bool res2 = mycomparator(v, vs[mid]);
            if (res1 == res2) {
                return true;
            } else if (res2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    } 
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        int pos = search(candidates, target);
        if (candidates[pos] > target) {
            candidates.erase(candidates.begin()+pos, candidates.end());
        } else {
            candidates.erase(candidates.begin()+pos+1, candidates.end());
        }

    	vector<vector<int> > init_comb;
        vector<vector<vector<int> > >combs;
		for (int i = 0; i < target+1; i++) {
			combs.push_back(init_comb);
		}

        // repeated vals
        for (int i = 0; i < candidates.size(); i++) {
            int cur = candidates[i];
            vector<int> v;
            int count = cur;
            while (count <= target) {
                v.push_back(cur);
                combs[count].push_back(v);
                sort(combs[count].begin(), combs[count].end(), mycomparator);
                count += cur;
            }
        }
        // comb
        for (int i = 1; i < target; i++) {
            int diff = target - i;
            vector<vector<int> > &sub_comb = combs[i];
            for (int comb_index = 0; comb_index < sub_comb.size(); comb_index++) {
                for (int j = 1; j <= diff && j <= i; j++) {
                    for (int k = 0; k < combs[j].size(); k++) {
                        vector<int> comb = combs[j][k];
                        comb.insert(comb.end(), sub_comb[comb_index].begin(), sub_comb[comb_index].end());
                        sort(comb.begin(), comb.end());
                        if (!find(combs[i+j], comb)) {
                            combs[i+j].push_back(comb);
                            sort(combs[i+j].begin(), combs[i+j].end(), mycomparator);
                        }
                    }
                }
            }
        }
        return combs[target];
    }
};
