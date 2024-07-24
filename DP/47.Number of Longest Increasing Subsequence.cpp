//https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
    
        vector<int> count(n, 1); 

        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]&&dp[j] + 1 > dp[i]) {
                
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Reset count[i] to count[j]
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // Add count[j] to count[i]
                    }
                }
            
            maxLength = max(maxLength, dp[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLength) {
               ans += count[i];
            }
        }

        return ans;
    }
};