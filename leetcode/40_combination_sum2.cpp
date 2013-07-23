// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

class Solution {
public:
    bool isDisjoint(vector<int> &a, vector<int> &b) {
        for (int i = 0, j = 0; i < a.size() && j < b.size(); ) {
            if (a[i] == b[j]) {
                return false;
            }
            if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        return true;
    }
    bool equal(vector<int> &a, vector<int> &b) {
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    bool contain(vector<vector<int> > &comb, vector<int> v) {
        for (int i = 0; i < comb.size(); i++) {
            if (equal(comb[i], v)) {
                return true;
            }
        }
        return false;
    }
    string v2s(vector<int> &num) {
        stringstream s;
        s << "[";
        for (int i = 0; i < num.size(); i++) {
            s << num[i] << ",";
        }
        s << "]";
        return s.str();
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // init
        vector<vector<vector<int> > > combs;
        for (int i = 0; i < target+1; i++) {
            vector<vector<int> > comb;
            combs.push_back(comb);
        }
        // first round - init
        sort(num.begin(), num.end());
        int same_count = 1;
        int last_num = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > target) {
                break;
            }
            vector<int> comb;
            if (last_num == num[i]) {
                same_count++;
            } else {
                same_count = 1;
                last_num = num[i];
            }
            if (same_count == 1) {
                comb.push_back(num[i]);
                combs[num[i]].push_back(comb);
                printf("[%d]+%s\n", num[i], v2s(comb).c_str());
                
            } else {
                if (num[i]*same_count <= target) {
                    for (int j = 0; j < same_count; j++) {
                        comb.push_back(num[i]);
                    }
                    combs[num[i]*same_count].push_back(comb);
                    printf("[%d]+%s\n", num[i]*same_count, v2s(comb).c_str());
                }
            }
        }
        // comnbine
        for (int i = 1; i < target; i++) {
            int diff = target - i;
            for (int base_index = 0; base_index < combs[i].size(); base_index++) {
                for (int j = 1; j <= i && j <= diff; j++) {
                    for (int add_index = 0; add_index < combs[j].size(); add_index++) {
                        if (!isDisjoint(combs[j][add_index], combs[i][base_index])) {
                            continue;
                        }
                        cout << v2s(combs[j][add_index]) << " append " << v2s(combs[i][base_index]) << endl;
                        vector<int> v = combs[j][add_index];
                        v.insert(v.end(), combs[i][base_index].begin(), combs[i][base_index].end());
                        sort(v.begin(), v.end());
                        if (contain(combs[i+j], v)) {
                            continue;
                        } 
                        combs[i+j].push_back(v);
                    }
                }
            }
        }
        return combs[target];
    }
};

int main() {
    // Start typing your code here...
    vector<int> num = {10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int> > res = s.combinationSum2(num, 8);
    cout << "---" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << s.v2s(res[i]) << endl;
    }
    
    return 0;
}
