//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution {
public:
    bool solve(int idx, int sum1, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        // base case
        if (sum1 == sum) {
            return true;
        }
        if (idx >= arr.size() || sum1 > sum) {
            return false;
        }

        if (dp[idx][sum1] != -1) {
            return dp[idx][sum1];
        }

        // option to skip the current element
        int take=0,skip=0;
        skip = solve(idx + 1, sum1, arr, sum, dp);

        if(sum1<sum){
         take = solve(idx + 1, sum1 + arr[idx], arr, sum, dp);
        }
        return dp[idx][sum1] = (skip + take);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, 0, arr, sum, dp);
    }
};
