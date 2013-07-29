class Solution {
public:
    void set(vector<string> &board, int x, int y) {
        for (int i = 0; i < board.size(); i++) {
            board[i][y] = '.';
        }
        for (int j = 0; j < board.size(); j++) {
            board[x][j] = '.';
        }
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            board[i][j] = '.';
        }
        for (int i = x, j = y; i >= 0 && j < board.size(); i--, j++) {
            board[i][j] = '.';
        }
        for (int i = x, j = y; i < board.size() && j >= 0; i++, j--) {
            board[i][j] = '.';
        }
        for (int i = x, j = y; i < board.size() && j < board.size(); i++, j++) {
            board[i][j] = '.';
        }
        board[x][y] = 'Q';
    }
    void search(int line, int max, vector<string> &board) {
        if (line == max) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < max; i++) {
            if (board[line][i] == 'A') {
                vector<string> old_board = board;
                set(board, line, i);
                search(line+1, max, board);
                board = old_board;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string line;
            for (int j = 0; j < n; j++) {
                // available
                line.push_back('A');
            }
            board.push_back(line);
        }
        
        search(0, n, board);
        
        return res;
    }
private:
    vector<vector<string> > res; 
};
