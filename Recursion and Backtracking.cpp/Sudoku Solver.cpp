//TC-O(9^n) n is the number of empty cells..n<=81..in worst case TC->O(9^81)
class Solution {
public:
    bool isCol(int i, int j, char k, vector<vector<char>>& board) {
        for (int a = 0; a < 9; a++) {
            if (board[i][a] == k)
                return false;
        }
        return true;
    }

    bool isRow(int i, int j, char k, vector<vector<char>>& board) {
        for (int o = 0; o < 9; o++) {
            if (board[o][j] == k)
                return false;
        }
        return true;
    }

    bool isSubMatrix(int i, int j, char k, vector<vector<char>>& board) {
        int x = (i / 3) * 3;
        int y = (j / 3) * 3;
        for (int l = x; l < x + 3; l++) {
            for (int m = y; m < y + 3; m++) {
                if (board[l][m] == k)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isRow(i, j, k, board) && isCol(i, j, k, board) && isSubMatrix(i, j, k, board)) {
                            board[i][j] = k;
                            if (solve(board)){
                                return true;// Correct recursive call
                            }   
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // If no valid number can be placed
                }
            }
        }
        return true; // The board is completely solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};