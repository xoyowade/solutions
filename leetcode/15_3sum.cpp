struct comparator {
  bool operator() (const vector<int>& a, const vector<int>& b) { 
      if (a[0] == b[0]) {
          if (a[1] == b[1]) {
              return a[2] < b[2];
          }
          return a[1] < b[1];
      }
      return a[0] < b[0];
  }
};
  
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        
        set<vector<int>, comparator> found;
        for (int i = 0; i < num.size() - 2; i++) {
            int l = i + 1;
            int r = num.size() - 1;
            while (l < r) {
                int sum = num[i] + num[l] + num[r];
                if (sum == 0) {
                    vector<int> v = {num[i], num[l], num[r]};
                    found.insert(v);
                    r--;
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        result.assign(found.begin(), found.end());
        return result;
    }
};
