//https://leetcode.com/problems/largest-divisible-subset/description/

//in this code memoization will give tle..tabulation works
class Solution {
public:
    void solve(int prev, int curr, std::vector<int>& ans, std::vector<int>& temp, std::vector<int>& nums,vector<vector<int>>&dp) {
        // Base case
        if (curr >= nums.size()) {
            //dekho ye kyo likhe hai?jb divisible nhi hoga to tree mera not take pe jayega fir waha se tree nivhe tk banega..aur jo divisible hai wo bhi neeche tk tree banayega..aur last me compare kar lenge ki jiske temp me jyada value store hai usko final ans me daal de...
            if (temp.size() > ans.size()) {
                ans = temp;
                 
            }
           return;
        }
      if(dp[prev+1][curr]!=-1){
        return ;
      }
        if (prev == -1 || nums[curr] % nums[prev] == 0) {
           temp.push_back(nums[curr]);
            solve(curr, curr + 1, ans, temp, nums,dp);
            temp.pop_back();
        }
      
        solve(prev, curr + 1, ans, temp, nums,dp);
       
    }

    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //solve(-1, 0, ans, temp, nums,dp);
       vector<int>dp(n,1);
       //isme hm ye store karenge ki suppose dp[3]=4..iska mtlb 4 length ka longest increasing mila..to ans[3] me hum index store karenge uska jisne dp[3] ko 4 banaya..mtlb last index store karenge isme.. 
       vector<int>prev_index(n,-1);
       
        int max_length = 1;
        int max_index = 0;

        // Build the dp and prev_index arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_index[i] = j;
                }
            }
            //tmko largest value ka track rakhna hai..
            if (dp[i] > max_length) {
                max_length = dp[i];
                max_index = i;
            }
        }
         vector<int> result;
        for (int i = max_index; i >= 0; i = prev_index[i]) {
            result.push_back(nums[i]);
            if (prev_index[i] == -1) break;
        }

        reverse(result.begin(), result.end());
      
      return result;
    }
};
