//https://leetcode.com/problems/count-number-of-nice-subarrays/description/

//TC-O(N)
//SC-O(N)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        int oddcount=0;
        int count=0;
        mp[oddcount]=1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2!=0){
                oddcount+=1;
            }
            if(mp.find(oddcount-k)!=mp.end()){
                count+=mp[oddcount-k];
            }
            mp[oddcount]++;
        }
        return count;

    }
};


//TC-O(N)
//SC-O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,prevcount=0,oddcount=0,result=0;

        while(j<n){
            if(nums[j]%2!=0){
                oddcount++;
                prevcount=0;
            }
            while(oddcount==k){
              prevcount++;
              if(nums[i]%2!=0){
                oddcount--;
              }
              i++;
            }

        result+=prevcount;
        j++;
        }
        return result;
    }
};