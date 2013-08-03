class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> dirs;
        int i = 0;
        while (i < path.length()) {
            int end = path.find_first_of('/', i+1);
            if (end == string::npos) {
                end = path.length();
            }
            string dir = path.substr(i+1, end-i-1);
            if (dir == "..") {
                if (dirs.size() > 0) {
                    dirs.pop_back();
                }
            } else if (dir.empty() || dir == ".") {
                // do nothing
            } else {
                dirs.push_back(dir);
            }
            i = end;
        }
        
        string s;
        for (int i = 0; i < dirs.size(); i++) {
            s += "/" + dirs[i];
        }
        if (s.empty()) {
            s = "/";
        }
        return s;
    }
};
