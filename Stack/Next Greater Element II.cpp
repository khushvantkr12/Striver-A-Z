//TC-O(N)
//SC-O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m=nums.size();
        stack<int>st;
        vector<int>ans(m,-1);
        for(int i=2*m-1; i>=0; i--){
         while(!st.empty() && nums[i%m]>=st.top()){
            st.pop();
         }
         if(i<m){
         if(!st.empty() && st.top()>nums[i]){
            ans[i]=st.top();
         }
         }
         if(i<m){
         if(st.empty()){
            ans[i]=-1;
         }
         }
         st.push(nums[i%m]);
      } 
      return ans;
    }
};