class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) {
            return;
        }

        // Include the current element
        temp.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], ans, temp); // Stay at the same index
        temp.pop_back();

        // Exclude the current element
        solve(i + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, ans, temp);
        return ans;
    }
};