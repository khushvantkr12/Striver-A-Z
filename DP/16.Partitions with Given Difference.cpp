//https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

//MEMOIZATION
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

//TABULATION
 int countPartitions(int n, int d, vector<int>& arr) {
        int x = accumulate(arr.begin(), arr.end(), 0);
        if (x < d || (x - d) % 2 != 0) {
            return 0; // If total sum < d or (x - d) is odd, no valid partitions
        }
          // x-y=d
        // abs(x-(sum-x))=d
        // 2x-sum=-d    eq(1)
        // 2x-sum=d    eq (2)
        // x=(sum+d)/2
        //  or x=(sum-d)/2
        // y=x-d
        // y=(sum-d)/2
        // or y=(sum+d)/2
       
        int sum=(x-d)/2;
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, 0)); // DP array with memoization

        //return solve(0, x, n, d, arr, (x-d)/2, dp);
        int MOD=1e9+7;
        for(int i=n; i>=0; i--){
            dp[i][0]=1;
        }
    
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=sum; j++){
                int take=0,skip=0;
                
                if(j>=arr[i]){
                take=dp[i+1][j-arr[i]]%MOD;
            }
            skip=dp[i+1][j];
            dp[i][j]=(take+skip)%MOD;
            }
            
        }
        return dp[0][sum];
   
    }
};