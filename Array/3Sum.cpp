//TC-:O(nlogn+n²log n){logn is insertion of element in set}
//approach-->first sort then make set of vector to store unique triplets then run O(n^2) loop to check.



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++){
            //slight optimization(-2,-2,-2,-1,0,0,0,2,2)here we can skip -2 which occurs more than once
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        for(auto it : s)
           ans.push_back(it);
        return ans;
    
    }
};