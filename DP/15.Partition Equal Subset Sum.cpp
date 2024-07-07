//https://leetcode.com/problems/partition-equal-subset-sum/description/

//memoization
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
//Tabulation
bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
         
         if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
         vector<vector<int>> dp(n + 1, vector<int>(target+ 1, 0));
        
        //return solve(0, 0, target, nums);

        //think about base case
        //jb target 0 hojayega tb index kya ho skta hai?
        for(int i=n-1; i>=0; i--){
            dp[i][0]=true;//0 isiliye kyoki target 0 hai tbhi index kuch bhi hoga
        }
        if(nums[n-1]<=target){
       dp[n-1][nums[n-1]]=true;
        }

         //dekho for loop humlog likhenge aise ki top down ka just opposite kar denge
        //suppose top down me start at index 0 then go down n-1..but for bottom up we start at index n-1 and go upto 0
       for(int i=n-1; i>=0; i--){
        for(int j=1; j<=target; j++){
            int take=0,skip=0;
            
            if(j-nums[i]>=0){
                take=dp[i+1][j-nums[i]];
            }
            skip=dp[i+1][j];
            dp[i][j]=take||skip;
        }
       }
       //yaha pe index n-1 se 0 jaa rha hai isiliye 0
       return dp[0][target];
    }
};

