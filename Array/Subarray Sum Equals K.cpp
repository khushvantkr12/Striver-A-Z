class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0; i<n; i++){
         sum+=nums[i];
         if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
         }
         mp[sum]++;
        }
        return count;
    }
};