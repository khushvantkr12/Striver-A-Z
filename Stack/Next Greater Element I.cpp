//BRUTE FORCE
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();  
      int m=nums2.size(); 
      
      vector<int>ans(n,-1);
      for(int i=0; i<n; i++){
        stack<int>st;
         for(int j=m-1; j>=0; j--){
            if(!st.empty() && nums1[i]==nums2[j]){
            while(!st.empty() && nums1[i]>st.top()){
                st.pop();
            }
            if(!st.empty() && st.top()>nums1[i]){
              ans[i]=st.top();
              break;
            }
            if(st.empty()){
                ans[i]=-1;
            }
            } else{
                st.push(nums2[j]);
            }

         }
      } 
      return ans;
    }
};





//TC-O(m+n)
//SC-O(m+n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();  
      int m=nums2.size(); 
      
      vector<int>ans(m,-1);
      stack<int>st;
      
      //apply NGE on nums2
      for(int i=m-1; i>=0; i--){
         while(!st.empty() && nums2[i]>st.top()){
            st.pop();
         }
         if(!st.empty() && st.top()>nums2[i]){
            ans[i]=st.top();
         }
         if(st.empty()){
            ans[i]=-1;
         }
         st.push(nums2[i]);
      } 
      //then we will find the res for nums1
      vector<int>res(n,-1);
      map<int,int>mp;
      for(int i=0; i<nums2.size(); i++){
        mp[nums2[i]]=i;
      }
      for(int i=0; i<n; i++){
        if(mp.find(nums1[i])!=mp.end()){
            res[i]=ans[mp[nums1[i]]];
        }
      }
      return res;
    }
};