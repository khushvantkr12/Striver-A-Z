//https://leetcode.com/problems/generate-parentheses/description/

// TC-O(2^(2*n))
// SC-O(N)
class Solution {
public:
    void solve(string s, int open, int close, int n, vector<string>& ans) {
        // Base case: if the string has 2*n characters, add it to the result
        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        
        if(open < n) {
            solve(s + '(', open + 1, close, n, ans);
        }

        if(close < open) {
            solve(s + ')', open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", 0, 0, n, ans); // Start with an empty string and 0 open/close
        return ans;
    }
};
