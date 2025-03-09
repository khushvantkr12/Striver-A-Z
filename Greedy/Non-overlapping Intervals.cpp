class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       int ans=0;
       int previous=0;
       for(int i=0; i<intervals.size(); i++){
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<" ";
       }
       for(int i=1; i<intervals.size(); i++){
         if(intervals[i][0]<intervals[previous][1]){//overlapping condn
             ans++;
             if(intervals[i][1]<intervals[previous][1]){
               previous=i;
             }
         }else{
             previous=i;
         }
       }
       return ans;
    }
};