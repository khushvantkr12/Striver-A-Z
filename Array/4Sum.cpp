class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++){
            //slight optimization(-2,-2,-2,-1,0,0,0,2,2)here we can skip -2 which occurs more than once
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1; j<nums.size(); j++){
               long long k = nums.size() - 1;
               long long l=j+1;
            while (l < k) {
                long long sum =(long long)nums[i] + nums[j] + nums[k]+nums[l];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k],nums[l]});
                    l++;
                    k--;
                } else if (sum < target) {
                    l++;
                } else {
                    k--;
                }
            }
        }
        }
        for(auto it : s)
           ans.push_back(it);
        return ans;
    }
};