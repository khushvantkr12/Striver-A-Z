//https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    int dp[201][20001]; // Reduce the size of the dp array
    
    bool solve(int idx, int sum, int target, vector<int>& nums) {
     if (sum == target) {
               return true;
       }
         if (idx >= nums.size()) {
              return false;
        }
       if(sum > target){
              return false;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        
       
       int include = solve(idx + 1, sum + nums[idx], target, nums);
        
       int exclude = solve(idx + 1, sum, target, nums);
        
        return dp[idx][sum] = include + exclude;
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
         
         if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, target, nums);
    }
};
