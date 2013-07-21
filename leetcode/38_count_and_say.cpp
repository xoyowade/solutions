class Solution {
    struct CharFreq {
        char c;
        int freq;
        CharFreq(char _c, int _freq): c(_c), freq(_freq) {}
    };
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string sequence;
        sequence.append(1, '1');
        for (int i = 1; i < n; i++) {
            int count = 0;
            char c;
            vector<CharFreq> freqs;
            for (int j = 0; j < sequence.length(); j++) {
                if (count == 0) {
                    c = sequence[j];
                    count++;
                } else {
                    if (c == sequence[j]) {
                        count++;
                    } else {
                        freqs.push_back(CharFreq(c, count));
                        c = sequence[j];
                        count = 1;
                    }
                }
            }
            if (count > 0) {
                freqs.push_back(CharFreq(c, count));
            }
            // generate sequence
            sequence.clear();
            for (int j = 0; j < freqs.size(); j++) {
                sequence.append(1, '0'+freqs[j].freq);
                sequence.append(1, freqs[j].c);
            }
        }
        return sequence;
    }
};
