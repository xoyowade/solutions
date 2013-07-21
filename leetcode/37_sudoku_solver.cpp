// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool rmCellPossible(vector<vector<vector<int> > > &set_possibles, int val, int row, int col) {
        vector<int> &cell_possibles = set_possibles[row][col];
		int old_len = cell_possibles.size();
		// printf("to rm %d from (%d, %d) %d left\n", val, row, col, old_len);
        for (int i = 0; i < cell_possibles.size(); i++) {
            if (cell_possibles[i] == val) {
				// printf("rm %d\n", val);
                cell_possibles[i] = cell_possibles[cell_possibles.size()-1];
                cell_possibles.pop_back();
				break;
            }
        }
        if (old_len > 1 && cell_possibles.size() == 1) {
			// printf("recursively check %d @(%d, %d)\n", cell_possibles.back(), row, col);
            if (!rmSetPossibles(set_possibles, cell_possibles.back(), row, col)) {
                return false;
            }
        }
        if (cell_possibles.size() == 0) {
			// printf("%d %d failed after rm\n", row, col);
            return false;
        }
        return true;
    }
    bool rmSetPossibles(vector<vector<vector<int> > > &set_possibles, int val, int row, int col) {
        const int size = set_possibles.size();
        const int subsize = sqrt(size);
        // rm col
        for (int i = 0; i < size; i++) {
            if (i != row) {
                if (!rmCellPossible(set_possibles, val, i, col)) {
                    return false;
                }
            }
        }
        // rm row
        vector<vector<int> > &row_possibles = set_possibles[row];
        for (int i = 0; i < size; i++) {
            if (i != col) {
                if (!rmCellPossible(set_possibles, val, row, i)) {
                    return false;
                }
            }
        }
        // rm squar
        int sub_row = row / subsize;
        int sub_col = col / subsize;
        for (int i = sub_row*subsize; i < sub_row*subsize + subsize; i++) {
            for (int j = sub_col*subsize; j < sub_col*subsize + subsize; j++) {
                if (i != row && j != col) {
                    if (!rmCellPossible(set_possibles, val, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool trySolve(vector<vector<vector<int> > > &set_possibles) {
        const int size = set_possibles.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                vector<int> &cell_possibles = set_possibles[i][j];
                if (cell_possibles.size() > 1) {
					vector<vector<vector<int> > > old_possibles = set_possibles;
                    for (int k = 0; k < cell_possibles.size(); k++) {
                        // try Kth val
                        int val = cell_possibles[k];
						// static int count = 0;
                        // printf("try %d at (%d,%d) begin %d\n", val, i, j, count);
                        cell_possibles.clear();
                        cell_possibles.push_back(val);
                        if (rmSetPossibles(set_possibles, val, i, j) &&
                            trySolve(set_possibles)) {
                            return true;
                        }
                        // printf("try %d at (%d,%d) end %d\n", val, i, j, count);
						// count++;
                        set_possibles = old_possibles;
                    }
					return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int size = board.size();
        const int subsize = sqrt(size);
		
        vector<int> all_possibles; 
		for (int i = 0; i < size; i++) {
			all_possibles.push_back(i+1);
		}
        vector<vector<vector<int> > > set_possibles;
        
        // init possibles
        for (int i = 0; i < size; i++) {
            vector<vector<int> > row_possibles;
            for (int j = 0; j < size; j++) {
                vector<int> cell_possibles;
                if (board[i][j] == '.') {
                    cell_possibles = all_possibles;
                } else {
                    cell_possibles.push_back(board[i][j] - '0');
                }
                row_possibles.push_back(cell_possibles);
            }
            set_possibles.push_back(row_possibles);
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                vector<int> &cell_possibles = set_possibles[i][j];
                if (cell_possibles.size() == 1) {
					// printf("check %d @(%d, %d)\n", cell_possibles.back(), i, j);
                    rmSetPossibles(set_possibles, cell_possibles.back(), i, j);
                }
            }
        }
        
        // try and check
        if (!trySolve(set_possibles)) {
			printf("not valid sudoku\n");
        }
        // copy back
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = set_possibles[i][j].back() + '0';
            }
        }
    }
};
void printBoard(vector<vector<char> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}    
}

const static int SIZE = 9;
void addRow(vector<vector<char> > &board, char raw[SIZE]) {
	vector<char> row;
	row.assign(raw, raw+SIZE);
	board.push_back(row);
}
int main() {
    // Start typing your code here...
    vector<vector<char> > board;
	char raw1[] = {'.','.','4','6','.','8','.','1','.'};
	addRow(board, raw1);
	char raw2[] = {'.','.','.','1','.','5','3','4','8'};
	addRow(board, raw2);
	char raw3[] = {'1','.','.','3','4','.','5','.','.'};
	addRow(board, raw3);
	char raw4[] = {'8','5','.','.','6','1','4','.','3'};
	addRow(board, raw4);
	char raw5[] = {'.','.','.','8','5','.','.','.','1'};
	addRow(board, raw5);
	char raw6[] = {'.','1','.','.','.','4','8','5','6'};
	addRow(board, raw6);
	char raw7[] = {'.','6','1','5','3','.','.','8','4'};
	addRow(board, raw7);
	char raw8[] = {'.','8','.','4','1','.','6','3','.'};
	addRow(board, raw8);
	char raw9[] = {'.','4','5','.','8','6','1','.','.'};
	addRow(board, raw9);
   
	printBoard(board); 
	printf("-------------\n");
    Solution s;
    s.solveSudoku(board);
	printBoard(board); 

    return 0;
}
