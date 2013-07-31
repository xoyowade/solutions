class Solution {
public:
    bool dfs(int cur, int n, int k) {
        if (cur == n) {
            count++;
            if (count == k) {
                for (int i = 0; i < n; i++) {
                    res += a[i]+'0';
                }
                return true;
            }
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            if (available[i]) {
                available[i] = false;
                a[cur] = i+1;
                if (dfs(cur+1, n, k)) {
                    return true;
                }
                available[i] = true;
            }
        }
        
        return false;
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        count = 0;
        res = "";
        finish = false;
        memset(available, 1, sizeof(available));
        
        dfs(0, n, k);
        
        return res;
    }
    int a[10];
    bool available[10];
    int count;
    string res;
    bool finish;
};
