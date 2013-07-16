struct comparator {
    bool operator() (const vector<int>& a, const vector<int>& b) const {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 4) return vector<vector<int> >();
        sort(num.begin(), num.end());
        set<vector<int>, comparator> result;
        for (int i = 0; i < num.size() - 3; i++) {
            for (int j = i+1; j < num.size() - 2; j++) {
                int l = j + 1;
                int r = num.size() - 1;
                while (l < r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum == target) {
                        vector<int> v = {num[i], num[j], num[l], num[r]};
                        result.insert(v);
                        l++;
                        r--;
                    } else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return vector<vector<int> >(result.begin(), result.end());
    }
};
