struct Point {
    int x;
    int y;
    Point(int i, int j) {
        x = i;
        y = j;
    }
};
class Solution {
public:
    bool go(vector<vector<char> > &board, int x, int y, 
            string &word, int p, vector<vector<bool> > &available) {
        if (available[x][y] && board[x][y] == word[p+1]) {
            available[x][y] = false;
            bool found = search(board, x, y, word, p+1, available);
            available[x][y] = true;
            if (found) {
                return true;
            }
        }
        return false;
    }
    bool search(vector<vector<char> > &board, int x, int y, 
                string &word, int p, vector<vector<bool> > &available) {
        if (p == word.length()-1) {
            return true;
        }              
        
        if (x > 0) {
            if (go(board, x-1, y, word, p, available)) {
                return true;
            }
        }
        if (y > 0) {
            if (go(board, x, y-1, word, p, available)) {
                return true;
            }
        }
        if (x < board.size()-1) {
            if (go(board, x+1, y, word, p, available)) {
                return true;
            }
        }
        if (y < board[0].size()-1) {
            if (go(board, x, y+1, word, p, available)) {
                return true;
            }
        }
        
        return false;
        
        
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0) {
            return true;
        }
        // build index
        vector<vector<bool> > available;
        map<char, vector<Point> > index;
        
        for (int i = 0; i < board.size(); i++) {
            vector<bool> line(board[i].size(), true);
            available.push_back(line);
            for (int j = 0; j < board[i].size(); j++) {
                char c = board[i][j];
                if (index.find(c) == index.end()) {
                    index[c] = vector<Point>();
                }
                index[c].push_back(Point(i,j));
            }
        }
        
        // find
        vector<Point> &heads = index[word[0]];
        for (int i = 0; i < heads.size(); i++) {
            int x = heads[i].x;
            int y = heads[i].y;
            available[x][y] = false;
            if (search(board, x, y, word, 0, available)) {
                return true;
            }
            available[x][y] = true;
        }
        
        return false;
    }
};
