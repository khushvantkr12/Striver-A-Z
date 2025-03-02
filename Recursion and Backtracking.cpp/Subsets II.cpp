class Solution {
public:
    void solve(int i,  vector<vector<int>>&ans, vector<int>& temp, vector<int>& nums) {
        if (i >= nums.size()) {
           ans.push_back(temp);
            return;
        }
        
        //take
        temp.push_back(nums[i]);
        solve(i+1,ans,temp,nums);
        temp.pop_back();

        //now we have to avoid duplicates
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        solve(idx,ans,temp,nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>>ans;
        solve(0, ans, temp, nums);

       return ans;
    }
};
