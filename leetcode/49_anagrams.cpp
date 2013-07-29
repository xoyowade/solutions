typedef struct stringcode_s {
    int index;
    int code[26];
    stringcode_s() {
        memset(code, 0, sizeof(code));
    }
    bool operator==(const struct stringcode_s &other) {
        for (int i = 0; i < 26; i++) {
            if (code[i] != other.code[i]) {
                return false;
            }
        }
        return true;
    }
} stringcode;
    
bool comparator(const stringcode &a, const stringcode &b) {
    for (int i = 0; i < 26; i++) {
        if (a.code[i] < b.code[i]) {
            return true;
        } else if (a.code[i] > b.code[i]) {
            return false;
        }
    }
    return false;
}

class Solution {
public:
 
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        vector<stringcode> strcodes;
        for (int i = 0; i < strs.size(); i++) {
            stringcode sc;
            sc.index = i;
            for(int j = 0; j < strs[i].length(); j++) {
                sc.code[strs[i][j]-'a']++;
            }
            strcodes.push_back(sc);
        }
        
        sort(strcodes.begin(), strcodes.end(), comparator);
        
        int start = 0;
        while (start < strcodes.size()-1) {
            if (strcodes[start] == strcodes[start+1]) {
                res.push_back(strs[strcodes[start].index]);
                int comp = start;
                for (start = start+1; start < strcodes.size(); start++) {
                    if (strcodes[comp] == strcodes[start]) {
                        res.push_back(strs[strcodes[start].index]);
                    } else {
                        break;
                    }
                }
            } else {
                start++;
            }
        }
        
        return res;
    }
};
