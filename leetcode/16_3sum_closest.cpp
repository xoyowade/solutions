class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int diff = INT_MAX;
        int diff_sign = true;
        for (int i = 0; i < num.size() - 2; i++) {
            int l = i + 1;
            int r = num.size() - 1;
            while (l < r) {
                int sum = num[i] + num[l] + num[r];
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    if (sum - target < diff) {
                        diff = sum - target;
                        diff_sign = true;
                    }
                    r--;
                } else {
                    if (target - sum < diff) {
                        diff = target - sum;
                        diff_sign = false;
                    }
                    l++;
                }
            }
        }
        return diff_sign ? target + diff : target - diff;
    }
};
