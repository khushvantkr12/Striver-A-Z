class Solution {
public:
    string removeKdigits(string num, int k) {
         stack<char>st;
         int n=num.size();
         string ans="";
         st.push(num[0]);
         if(num.size()==1 && k>=1){
           return "0";
         }
         for(int i=1; i<n; i++){
            while(!st.empty() && k>=1 && num[i]<st.top()){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
         }
            //in sab ke baad bhi agar "112" aajae to hm pop krdenge
            while(k>0){
                st.pop();
                k--;
            }
         while(!st.empty()){
            ans+=st.top();
            st.pop();
         }
         reverse(ans.begin(),ans.end());
         for(int i=0; i<ans.size(); i++){
            if(ans[i]=='0'){
                continue;
            }else{
                return ans.substr(i,ans.size());
            }
         }
         
         return "0";
    }
};