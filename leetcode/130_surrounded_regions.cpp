class Solution {
public:
    bool isX(vector<vector<char> > &board, int i, int j) {
        return board[i][j] == 'X';
    }
    bool isO(vector<vector<char> > &board, int i, int j) {
        return board[i][j] == 'O';
    }
    void bfs(vector<vector<char> > &board, int i, int j, int mark, bool &to_change) {
        queue<vector<int> > q;
        vector<int> pos = {i, j};
        q.push(pos);
        
        while (!q.empty()) {
            pos = q.front();
            q.pop();
            i = pos[0];
            j = pos[1];
        
            if (!isO(board, i, j)) continue;
            to_change = to_change && (i > 1 || isX(board, i-1, j));
            to_change = to_change && (j > 1 || isX(board, i, j-1));
            to_change = to_change && (i < board.size()-2 || isX(board, i+1, j));
            to_change = to_change &&  (j < board[0].size()-2 || isX(board, i, j+1));
            
            mark_board[i][j] = mark;
            board[i][j] = 'm';
            
            if (i < board.size()-2 && isO(board, i+1, j)) {
                pos = {i+1, j};
                q.push(pos);
            }
            if (j < board[0].size()-2 && isO(board, i, j+1)) {
                pos = {i, j+1};
                q.push(pos);
            }
            if (i > 1 && isO(board, i-1, j)) {
                pos = {i-1, j};
                q.push(pos);
            }
            
            if (j > 1 && isO(board, i, j-1)) {
                pos = {i, j-1};
                q.push(pos);
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (board.empty()) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        marks.clear();
        mark_board.clear();
        for (int i = 0; i < rows; i++) {
            mark_board.push_back(vector<int>(cols, 0));
        }
        int mark = 1;
        marks.push_back(false); // dummy
        for (int i = 1; i < rows-1; i++) {
            for (int j = 1; j < cols-1; j++) {
                if (board[i][j] == 'O') {
                    bool to_change = true;
                    bfs(board, i, j, mark++, to_change);
                    marks.push_back(to_change);
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (board[i][j] == 'm') {
                    board[i][j] = marks[mark_board[i][j]] ? 'X' : 'O';
                }
            }
        }
    }
    vector<vector<int> > mark_board;
    vector<bool> marks;
};

public class SolutionByPeking2 {
    int m,n;
    char[][] board;
    Queue<Integer> queue=new LinkedList<Integer>();
    
    void fill(int x, int y){
        if(x<0 || x>=m || y<0 || y>=n || board[x][y]!='O') return;
        queue.offer(x*m+y);
        board[x][y]='D';
    }
    
    void bfs(int x, int y){
        fill(x,y);
        
        while(!queue.isEmpty()){
            int curr=queue.poll();
            int i=curr/n;
            int j=curr%n;
            
            fill(i-1,j);
            fill(i+1,j);
            fill(i,j-1);
            fill(i,j+1);
        }
    }
    
    public void solve(char[][] board){
        if(board==null || board.length==0) return;
        this.board=board;
        m=board.length;
        n=board[0].length;
        
        for(int j=0;j<n;j++){
            bfs(0,j);
            bfs(m-1,j);
        }
        
        for(int i=1;i<m-1;i++){
            bfs(i,0);
            bfs(i,n-1);
        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='D') board[i][j]='O';
            }
    }
}

