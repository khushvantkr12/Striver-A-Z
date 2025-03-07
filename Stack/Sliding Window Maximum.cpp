class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //basically idea is index ko dq me store krte jaao piche se aur jb mera nums[j] bada hoga
        //  nums[dq.back] se to hm element ko pop krte jaayenge jb tk nums[j] se bada na mil jaae.
        //  aur mera front me hamesa bada element hi rhega..aur agar window ka size excced kiya to front
        //   se pop kr denge
        int n=nums.size();
        deque<int>dq;
        int j=0;
        vector<int>ans;
        while(j<n){
            if(!dq.empty() && j-k+1>dq.front()){
                //mtlb window ke bahar hogya
                dq.pop_front();
            }
            // Remove smaller elements (they will never be needed)
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j>=k-1){
                ans.push_back(nums[dq.front()]);
            }
            j++;
        }
        return ans;
    }
};