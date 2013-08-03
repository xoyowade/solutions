class Solution {
public:
    bool match_word(string &S, const int pos, const int len, map<string, int> &keys, int step) {
        if (step == 0) {
            return true;
        }
        string word = S.substr(pos, len);
        if (keys[word] > 0) {
            keys[word]--;
            if (match_word(S, pos+word.length(), len, keys, step-1)) {
                return true;
            }
        }
        
        return false;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        map<string, int> keys;
        for (int i = 0; i < L.size(); i++) {
            keys[L[i]] += 1;
        }
        int word_len = L[0].length();
        for (int i = 0; i < S.length()-L.size()*word_len+1; i++) {
            map<string, int> available_keys = keys;
            if (match_word(S, i, word_len, available_keys, L.size())) {
                res.push_back(i);
            }
        }
        return res;
    }
};
