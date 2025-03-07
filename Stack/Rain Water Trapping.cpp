class Solution {
public:
    int trap(vector<int>& height) {
        //idea is if u stand at index i then store it maxRight and maxLeft value in 2 diff vector
        // and take minimum and subtract it with height[i] then sum up all thats it

        int n=height.size();
        vector<int>maxRight(n,1); 
        vector<int>maxleft(n,1);

        //first find maxRight
        int maxi1=INT_MIN;
        for(int i=n-1; i>=0; i--){
          maxi1=max(maxi1,height[i]);
          maxRight[i]=maxi1;
        } 

        //first find maxleft
        int maxi2=INT_MIN;
        for(int i=0; i<n; i++){
          maxi2=max(maxi2,height[i]);
          maxleft[i]=maxi2;
        } 
      //then apply formula
      long long ans=0;
      for(int i=0; i<n; i++){
        ans=ans+min(maxleft[i],maxRight[i])-height[i];
      }
      return ans;
    }
};