//TC-(O(n*m)+O(n*2m))//inside solve 2 loop are runs which takes O(m+m)=O(2m),so O(n*2m) and n times run solve function
//SC-O(m) 
class Solution {
public:
    int solve(vector<int>& heights){
         int n=heights.size();
        vector<int>LtoR(n,1);
        vector<int>RtoL(n,1);
        stack<int>st1;
        stack<int>st2;
        
        //from right to left
        for(int i=n-1; i>=0; i--){
            while(!st1.empty() && heights[st1.top()]>heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                RtoL[i]=n-i;
            }else{
                RtoL[i]=st1.top()-i;
            }
            st1.push(i);
        }

        //from left to right
        for(int i=0; i<n; i++){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                LtoR[i]=i+1;
            }else{
                LtoR[i]=i-st2.top();
            }
            st2.push(i);
        }
        int res=INT_MIN;
        for(int i=0; i<n; i++){
            res=max(res,(LtoR[i]+RtoL[i]-1)*heights[i]);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //basically harek row me maximum rect in histogram find krna hai aur last me sbka max lelena hai thats it
    
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=INT_MIN;
    vector<int>heights(m,0);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
          if(matrix[i][j]=='1'){
            heights[j]++;
          }else{
            heights[j]=0;
          }
        }
    //     for(int i=0; i<heights.size(); i++){
    //     cout<<heights[i]<<" ";
    //  }cout<<endl;
        //histogram ko call krdo
        int ans=solve(heights);
        maxi=max(maxi,ans);
        //cout<<maxi<<endl;
    }
    //  for(int i=0; i<heights.size(); i++){
    //     cout<<heights[i]<<" ";
    //  }cout<<endl;
     return maxi;
    }
};