class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dis;
        vector<int> first_line;
        for (int i = 0; i <= word2.length(); i++) {
            first_line.push_back(i);
        }
        dis.push_back(first_line);
        for (int i = 1; i <= word1.length(); i++) {
            vector<int> line(word2.length()+1, 0);
            line[0] = i;
            dis.push_back(line);
        }
        
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                int del = dis[i-1][j] + 1;
                int ins = dis[i][j-1] + 1;
                int rep = dis[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
                dis[i][j] = min(min(del, ins), rep);
            }
        }
        
        return dis[word1.length()][word2.length()];
    }
};
