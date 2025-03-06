class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //jis bhi index pe ho waha se left aur right me bs ye nikal lo ki mere ya mera se bada next greater kitne elements hai
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
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi,(LtoR[i]+RtoL[i]-1)*heights[i]);
        }
        return maxi;
    }
};