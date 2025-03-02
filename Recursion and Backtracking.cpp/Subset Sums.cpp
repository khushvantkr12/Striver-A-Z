class Solution {
public:
    void solve(int i, vector<int>& arr, vector<int>& ans, int sum) {
        // Base Case
        if (i == arr.size()) {
            ans.push_back(sum);
            return;
        }

        // Include the current element
        solve(i + 1, arr, ans, sum + arr[i]);

        // Exclude the current element
        solve(i + 1, arr, ans, sum);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        solve(0, arr, ans, 0);
        return ans;
    }
};