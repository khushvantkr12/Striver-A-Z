//TC-O(N*M*4^L)

class Solution {
public:
    bool solve(int i, int j, string &s, string &word, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        //base case
        if (s == word) return true;  
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || s.size() > word.size()) return false;


        s += board[i][j];
        visited[i][j] = true;

        // Explore all four directions
        bool found = solve(i + 1, j, s, word, visited, board) ||
                     solve(i, j + 1, s, word, visited, board) ||
                     solve(i - 1, j, s, word, visited, board) ||
                     solve(i, j - 1, s, word, visited, board);

        // Backtrack
        s.pop_back();
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]&&board[i][j] == word[0]) {  
                    string s = "";
                    if (solve(i, j, s, word, visited, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
