//TOP DOWN

// class Solution {
// public:
//     int step(int index, int n, vector<int>& dp) {
//         if (index == n)
//             return 1;
//         if (index > n)
//             return 0;

//         if (dp[index] != -1)
//             return dp[index];

//         dp[index] = step(index + 1, n, dp) + step(index + 2, n, dp);
//         return dp[index];
//     }

//     int climbStairs(int n) {
//         vector<int> dp(n + 2, -1);
//         dp[n] = 1, dp[n + 1] = 0;
//         return step(0, n, dp);
//     }
// };

//BOTTOM UP

class Solution {
public:
int climbStairs(int n) {
     vector<int> dp(n + 2, -1);
     dp[n] = 1, dp[n + 1] = 0;

     for(int i=n-1; i>=0; i--)
         dp[i]=dp[i+1]+dp[i+2];
     
     return dp[0];
}
};