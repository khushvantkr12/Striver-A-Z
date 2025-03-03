TC-O(4^(n^2)) SC-O(n^2)
//with the help of pass by refernce(str)
class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>> &mat, vector<string>& ans, vector<vector<bool>>& visited, string& str) {
        // Base Case: Reached bottom-right
        if (i == n - 1 && j == n - 1) {
            ans.push_back(str);
            return;
        }

        // Boundary & Constraint Checks
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || mat[i][j] == 0) {
            return;
        }

        visited[i][j] = true; // Mark cell as visited

        // Move Down
        str.push_back('D');
        solve(i + 1, j, n, mat, ans, visited, str);
        str.pop_back(); // Backtrack

        // Move Right
        str.push_back('R');
        solve(i, j + 1, n, mat, ans, visited, str);
        str.pop_back(); // Backtrack

        // Move Up
        str.push_back('U');
        solve(i - 1, j, n, mat, ans, visited, str);
        str.pop_back(); // Backtrack

        // Move Left
        str.push_back('L');
        solve(i, j - 1, n, mat, ans, visited, str);
        str.pop_back(); // Backtrack

        visited[i][j] = false; // Unmark the cell
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return {}; // No path exists

        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        string path = ""; 
        solve(0, 0, n, mat, ans, visited, path); 

        sort(ans.begin(), ans.end()); // Sort lexicographically

        return ans;
    }
};

//pass by value (str)
class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>> &mat, vector<string>& ans, vector<vector<bool>>& visited, string str) {
        // Base Case: Reached bottom-right
        if (i == n - 1 && j == n - 1) {
            ans.push_back(str);
            return;
        }

        // Boundary & Constraint Checks
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || mat[i][j] == 0) {
            return;
        }

        visited[i][j] = true; // Mark cell as visited

        
            solve(i + 1, j, n, mat, ans, visited, str + 'D');
            solve(i, j + 1, n, mat, ans, visited, str + 'R');
            solve(i - 1, j, n, mat, ans, visited, str + 'U');
            solve(i, j - 1, n, mat, ans, visited, str + 'L');
            //WHY NOT WE POP BACK STR
            //because we pass str as pass by value so it store copies of itself thats why we do not need to pop_back
            visited[i][j] = false; // Backtrack
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return {}; // No path exists

        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        solve(0, 0, n, mat, ans, visited, "");

        sort(ans.begin(), ans.end()); // Sort lexicographically

        return ans;
    }
};

