class Solution {
public:
    int getLine(vector<string> &words, int p, int L, vector<string> &res) {
        
        vector<string> line_words;
        int least_len = 0;
        while (least_len < L && p < words.size()) {
            string &word = words[p];
            if (least_len + word.length() > L) {
                break;
            }
            least_len += word.length()+1;
            line_words.push_back(word);
            p++;
        }
        // last line or one word
        if (p == words.size() || line_words.size() == 1) {
            string s;
            for (int i = 0; i < line_words.size(); i++) {
                s += line_words[i];
                s += ' ';
            }
            if (L > s.length()) {
                s.insert(s.length(), L-s.length(), ' ');
            } else if (L < s.length()) {
                s.pop_back();
            }
            res.push_back(s);
            return p;
        }
        
        least_len--;
        
        int num_space = line_words.size()-1;
        int extra_num = L - least_len;
        int extra_per_space = extra_num/num_space;
        vector<int> spaces(num_space, 1+extra_per_space);
        int extra_num_left = extra_num - extra_per_space*num_space;
        int i = 0;
        while (extra_num_left-- > 0) {
            spaces[i++] += 1;
        }
        
        string s;
        for (int i = 0; i < line_words.size()-1; i++) {
            s += line_words[i];
            s.insert(s.length(), spaces[i], ' ');
        }
        s += line_words[line_words.size()-1];
        
        res.push_back(s);
        
        return p;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        if (L == 0) {
            res.push_back(words[0]);
            return res;
        }
        int p = 0;
        while (p < words.size()) {
            p = getLine(words, p, L, res);
        }
        return res;
    }
};
