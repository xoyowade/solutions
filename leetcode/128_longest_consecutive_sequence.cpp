class Solution {
public:
    int count(unordered_set<int> &set, int num) {
        int count = 0;
        int cur = num;
        while (set.find(cur) != set.end()) {
            set.erase(cur);
            count++;
            cur++;
        }
        cur = num-1;
        while (set.find(cur) != set.end()) {
            set.erase(cur);
            count++;
            cur--;
        }
        return count;
    }
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        set.insert(num.begin(), num.end());
        
        int max_len = 1;
        for (int i = 0; i < num.size(); i++) {
            max_len = max(max_len, count(set, num[i]));
        }
        
        return max_len;
    }
    int longestConsecutive_sort(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int max_len = 1;
        int len = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i-1]+1) {
                len++;
            } else if (num[i] != num[i-1]) {
                max_len = max(max_len, len);
                len = 1;
            }
        }
        return max(len, max_len);
    }
};
