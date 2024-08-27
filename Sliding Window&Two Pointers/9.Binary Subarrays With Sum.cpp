//https://leetcode.com/problems/binary-subarrays-with-sum/description/

//TC-O(N)
//SC-O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        mp[0]=1;
        int sum=0, count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                count+=mp[sum-goal];
            }
            
            mp[sum]++;
        }
        return count;
    }
};

//TC-O(N)
//SC-O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int i=0,j=0,sum=0,count=0,zero_count=0;

        while(j<n){
            sum+=nums[j];
        
        while(i<j && (nums[i]==0 || sum>goal)){
            if(nums[i]==0){
                zero_count++;
            }else{
                zero_count=0;
            }
            sum-=nums[i];
            i++;

        }
          
          if(sum==goal){
            count+=1+zero_count;
          }
            j++;
        }
        return count;
    }
};