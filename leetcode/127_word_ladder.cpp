class Solution {
public:
    bool canGo(string &from, string &to) {
        int diff = 0;
        for (int i = 0; i < from.length(); i++) {
            diff += from[i] != to[i] ? 1 : 0;
        }
        return diff == 1;
    }
    void dfs(string &start, string &end, int len, unordered_set<string> &dict) {
        if (start == end) {
            // +1 to pass oj
            res = min(res, len+1);
            return;
        }
        
        for (int i = 0; i < start.length(); i++) {
            char old = start[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == old) {
                    continue;
                }
                start[i] = c;
                if (used.find(start) == used.end() && 
                    dict.find(start) != used.end()) {
                    used.insert(start);
                    dfs(start, end, len+1, dict);
                    used.erase(start);
                }
            }
            start[i] = old;
        }
        
        return;
    }
    int ladderLength_dfs(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = INT_MAX;
        used.clear();
        
        dfs(start, end, 0, dict);
        
        return res == INT_MAX ? 0 : res;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        used.clear();
        
        int len = 1;
        queue<string> q;
        q.push(start);
        int count = q.size();
        while (!q.empty()) {
            if (count == 0) {
                len++;
                count = q.size();
            }
            count--;
            start = q.front();
            q.pop();
            if (start == end) {
                return len;
            }
            for (int i = 0; i < start.length(); i++) {
                char old = start[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == old) {
                        continue;
                    }
                    start[i] = c;
                    if (start == end) {
                        return len+1;
                    }
                    if (used.find(start) == used.end() && 
                        dict.find(start) != dict.end()) {
                        q.push(start);
                        used.insert(start);
                    }
                }
                start[i] = old;
            }
        }
        
        return 0;
    }
    
    int res;
    unordered_set<string> used;
};
