class Solution {
public:
    int solve(int idx,int sum,int n,vector<int>& nums, int target){
        //base
        if(idx==n){
            if(sum==target){
                return 1;
            }
            return 0;
        }
       if(idx>n){
        return 0;
       }


        int plustake=0,minustake=0;
        
        plustake=solve(idx+1,sum+nums[idx],n,nums,target);
        minustake=solve(idx+1,sum-nums[idx],n,nums,target);
        return plustake+minustake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(0,0,n,nums,target);
    }
};