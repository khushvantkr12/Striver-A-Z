class Solution {
public:
    void solve(int i,int k,int n,vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums){
        //base
      if(k==0 && n==0){
        ans.push_back(temp);
        return;
      }
     if(k<0 || n<0 || i>=nums.size()){
        return;
     }
       
       temp.push_back(nums[i]);
       solve(i+1,k-1,n-nums[i],ans,temp,nums);
       temp.pop_back();
       solve(i+1,k,n,ans,temp,nums);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,k,n,ans,temp,nums);
        return ans;
    }
};