class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        map<int,int>mp;
        int sum=0;
        int n=arr.size();
        mp[0]=-1;
        int maxi=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
           // mp[sum]=i;
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]);
            }else{
            mp[sum]=i;
            }
        }
        return maxi;
    }
};