//https://leetcode.com/problems/subarrays-with-k-different-integers/description/

//TC-O(2N)//2 times calling function
//SC-O(N)
class Solution {
public:
    
    //Total count of subarrays having <= k distict elements
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        int i = 0; 
        int j = 0;
        
        int count = 0;
        
        while(j < n) {
            
            mp[nums[j]]++;
            
            while(mp.size() > k) {
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            count += (j-i+1); //ending at j
            j++;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //the intution is:sabse pahle hm count <=k wala nikal lenge sabka lekin usme dikkat ye hai ki suppose k=3 hai to usme k=2,k=1 wala bhi aagya hoga count to hmko usko remove krna hoga..so hm "k-1" tk ka count nikalenge ab k-1 me count jo niklega wo k=2,k=1 ka hoga..aur last me dono ko minus kar denge..hogya
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};
