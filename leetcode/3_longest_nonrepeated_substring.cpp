// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;

class Solution {
public:
    void update(int c, int* alphabet, int* cur_len) {
        int index = alphabet[c];
        int back = 0;
        for (int i = 0; i < 26; i++) {
            if (0 < alphabet[i] && alphabet[i] <= index) {
				// printf("rm char %c @ %d(<=%d)\n", 'a'+i, alphabet[i], index);
                alphabet[i] = 0;
                back++;
            }
        }
        *cur_len -= back;
    }
    
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int alphabet[26];
        memset(alphabet, 0, 26*sizeof(int));
		for (int i = 0; i < 26; i++) {
			printf("%c %d\n", 'a'+i, alphabet[i]);
		}
        int max_len = 0, cur_len = 0;
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (alphabet[index] != 0) {
                if (max_len < cur_len) {
                    max_len = cur_len;
                }
                update(index, alphabet, &cur_len);
                // printf("handle %c with len %d\n", s[i], cur_len);
            }
            alphabet[index] = i+1;
            cur_len++;
        }
        if (max_len < cur_len) {
            max_len = cur_len;
        }
        return max_len;
    }
};
    
int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcde") << endl;

    return 0;
}
