class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min_start = 0;
        int min_len = INT_MAX;
        map<char, int> chars;
        for (int i = 0; i < T.length(); i++) {
            chars[T[i]]++;
        }
        int cur_start = 0;
        int count = T.length();
        map<char, int> counts = chars;
        for (int i = 0; i < S.length(); i++) {
            if (chars[S[i]] > 0) {
                if (counts[S[i]]-- > 0 && --count == 0) {
                    // get min cur window
                    while (true) {
                        if (chars[S[cur_start]] == 0) {
                            cur_start++;
                        } else if (counts[S[cur_start]] < 0) {
                            counts[S[cur_start]]++;
                            cur_start++;
                        } else {
                            break;
                        }
                    }
                    int len = i - cur_start + 1;
                    // save min window
                    if (len < min_len) {
                        min_len = len;
                        min_start = cur_start;
                    }
                    // advance window
                    count++;
                    counts[S[cur_start]]++;
                    cur_start++;
                }
            }
        }
        if (min_len == INT_MAX) {
            return "";
        } else {
            return S.substr(min_start, min_len);
        }
    }
};
