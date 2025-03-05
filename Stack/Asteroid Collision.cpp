class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int>st;
       int n=asteroids.size();
       
       for(int j=0; j<n; j++){
        if(st.empty() && asteroids[j]<0 || !st.empty() && st.top()<0 && asteroids[j]<0){
        st.push(asteroids[j]);
       }
        else if(asteroids[j]>0){
            st.push(asteroids[j]);
        }else{
            while(!st.empty() && st.top()>0 && abs(asteroids[j])>st.top()){
                st.pop();
                if(st.empty() || st.top()<0 && asteroids[j]<0){
                    st.push(asteroids[j]);
                }
            }
            if(!st.empty() && st.top()>0 && abs(asteroids[j])==st.top()){
                st.pop();
            }
        }
       
       } 
       if(st.empty()){
        return {};
       }

       vector<int>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};