//https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
//MEMOIZATION
//TC-O(N^2)
//SC-O(N^2)+O(N)//extra stack space 
    int solve(int prev,int curr,vector<int>& nums){
        //base
       if(curr>=nums.size()){
        return 0;
       }

        int take=0,skip1=0;
        if(prev==-1||nums[curr]>nums[prev]){
            take=1+solve(curr,curr+1,nums);
            
        }
            skip1=solve(prev,curr+1,nums);
            
        return max(take,skip1);
    }
    int lengthOfLIS(vector<int>& nums) {
          int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
       //TABULATION
        
        for (int i = n; i>=0; --i) {
            dp[n][i] = 0; 
            dp[i][n] = 0; 
        }
       //TC-O(N^2)
      //SC-O(N^2)
        int ans=0;
        for (int i = n - 1; i >= 0; --i) {
            for (int prev = i - 1; prev >= -1; --prev) {
                int take = 0, skip = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take= 1 + dp[i+1][i+1];
                }
                skip = dp[i + 1][prev+1];
                dp[i][prev + 1] = max(take, skip);
            }
        }
//  for(int i=0; i<dp.size(); i++){
//         for(int j=0; j<dp[0].size(); j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//        }
         return dp[0][0];

     //Method 2:---
    //TC-O(N^2)
    //SC-O(N)
     vector<int>dp(n,1);
         //LIS ending at its ith index
       //DEKHO SIMPLE QUESTION PUCHNA HAI KI: j puchega i se ki tujhpe end hone wala sabse maximum subsequence kya hai? aur kya tum mere se chota ho agar ha to apna value ko mere sath add kar do..
       
       int maxlength=0;
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxlength = max(maxlength, dp[i]);
        }

        return maxlength;

        //Method 3:---
        //lazy Sorting
        //TC-O(NLOGN)
        //SC-O(N)

        class Solution {
        public:
    int lengthOfLIS(vector<int>& nums) {
        //dekho isme karna ye hai ki ..harek element apna just greater element ya apna equal khojega..(just bada)..agar usko apna next bada ya equal mil gya to wo usse usko replace kr dega..agar suppose kro nhi mila to wo us vector me largest element hoga to vo vector me push ho jayega...
        //jis order me value store hoga ans me wahi mera LIS banega
         int n = nums.size();
      
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (ans.back() < nums[i]) {
                ans.push_back(nums[i]);
            } else {
               int it = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();
                ans[it]= nums[i];//ye replace kr dega pahle wale index ko aur uske jagah pe naya value rakh dega
            }
        }
        return ans.size();
    }
};
    }
};
//DRY RUN
//Input: nums = [0,1,0,3,2,3]
Fill the dp table based on the conditions:

i = 5 (nums[i] = 3):
prev = 4 (nums[prev] = 2): nums[i] > nums[prev], so take = 1 + dp[6][6] = 1 + 0 = 1.
prev = 3 (nums[prev] = 3): nums[i] == nums[prev], so take = 0.
prev = 2 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[6][6] = 1 + 0 = 1.
prev = 1 (nums[prev] = 1): nums[i] > nums[prev], so take = 1 + dp[6][6] = 1 + 0 = 1.
prev = 0 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[6][6] = 1 + 0 = 1.
prev = -1: take = 1 + dp[6][6] = 1 + 0 = 1.
i = 4 (nums[i] = 2):
prev = 3 (nums[prev] = 3): nums[i] < nums[prev], so take = 0.
prev = 2 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[5][5] = 1 + 1 = 2.
prev = 1 (nums[prev] = 1): nums[i] > nums[prev], so take = 1 + dp[5][5] = 1 + 1 = 2.
prev = 0 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[5][5] = 1 + 1 = 2.
prev = -1: take = 1 + dp[5][5] = 1 + 1 = 2.
i = 3 (nums[i] = 3):
prev = 2 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[4][4] = 1 + 3 = 4.
prev = 1 (nums[prev] = 1): nums[i] > nums[prev], so take = 1 + dp[4][4] = 1 + 3 = 4.
prev = 0 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[4][4] = 1 + 3 = 4.
prev = -1: take = 1 + dp[4][4] = 1 + 3 = 4.
i = 2 (nums[i] = 0):
prev = 1 (nums[prev] = 1): nums[i] < nums[prev], so take = 0.
prev = 0 (nums[prev] = 0): nums[i] == nums[prev], so take = 0.
prev = -1: take = 1 + dp[3][3] = 1 + 0 = 1.
i = 1 (nums[i] = 1):
prev = 0 (nums[prev] = 0): nums[i] > nums[prev], so take = 1 + dp[2][2] = 1 + 1 = 2.
prev = -1: take = 1 + dp[2][2] = 1 + 1 = 2.
i = 0 (nums[i] = 0):
prev = -1: take = 1 + dp[1][1] = 1 + 1 = 2.
