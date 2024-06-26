//https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference


#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int idx, int x, int n, int d, vector<int>& arr, int sum, vector<vector<int>>& dp) {
        // Base case
        if (idx == n) {
            if (sum - (x - sum) == d && sum >= x - sum) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        int take = solve(idx + 1, x, n, d, arr, sum + arr[idx], dp) % MOD;
        int skip = solve(idx + 1, x, n, d, arr, sum, dp) % MOD;

        return dp[idx][sum] = (take + skip) % MOD;
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int x = accumulate(arr.begin(), arr.end(), 0);
        if (x < d || (x - d) % 2 != 0) {
            return 0; // If total sum < d or (x - d) is odd, no valid partitions
        }
        
        
        vector<vector<int>> dp(n, vector<int>(x + 1, -1)); // DP array with memoization

        return solve(0, x, n, d, arr, 0, dp);
    }
};
