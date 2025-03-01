class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x=n*(n+1)/2;
        int y=accumulate(nums.begin(),nums.end(),0);
        return x-y;
    }
};