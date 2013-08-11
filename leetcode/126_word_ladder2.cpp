class Solution {
public:
   void genPath(const string &begin, map<string, unordered_set<string> > &traces, vector<string> &path) {
        path.push_back(begin);
        if (traces[begin].size() == 0) {
            vector<string> npath(path);
            reverse(npath.begin(), npath.end());
            res.push_back(npath);
            path.pop_back();
            return;
        }
        const unordered_set<string> &trace = traces[begin];
        unordered_set<string>::const_iterator iter = trace.begin();
        while (iter != trace.end()) {
            genPath(*iter++, traces, path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        map<string, unordered_set<string> > traces;
        unordered_set<string>::iterator iter = dict.begin();
        while (iter != dict.end()) {
            traces[*iter++] = unordered_set<string>();
        }
        
        vector<string> path;
        if (start == end) {
            path.push_back(end);
            path.push_back(start);
            reverse(path.begin(), path.end());
            res.push_back(path);
            return res;
        }
        unordered_set<string> cur;
        unordered_set<string> next;
        cur.insert(start);
        
        dict.erase(start);
        vector<string> level_used;
        
        while (!cur.empty() || !next.empty()) {
            unordered_set<string>::iterator iter;
            for (iter = cur.begin(); iter != cur.end(); iter++) {
                string s = *iter;    
                string from(s);
                for (int i = 0; i < s.length(); i++) {
                    char old = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) {
                            continue;
                        }
                        s[i] = c;
                        if (dict.find(s) != dict.end()) {
                            next.insert(s);
                            traces[s].insert(from);
                            level_used.push_back(s);
                        }
                    }
                    s[i] = old;
                }
            }
            if (traces[end].size()>0) {
                break;
            }
            for (int i = 0; i < level_used.size(); i++) {
                dict.erase(level_used[i]);
            }
            level_used.clear();
            swap(cur, next);
            next.clear();
        }
        
        if (traces[end].size()>0) {
            genPath(end, traces, path);
        }
        
        return res;
    }
    vector<vector<string> > res;
};
