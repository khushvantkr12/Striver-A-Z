vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
     stack<int>st;
     vector<int>ans(n,-1);
     
     for(int i=0; i<n; i++){
         while(!st.empty() && st.top()>=A[i]){
             st.pop();
         }
         if(!st.empty() && st.top()<A[i]){
             ans[i]=st.top();
         }
         if(st.empty()){
             ans[i]=-1;
         }
         st.push(A[i]);
     }
     return ans;
}
