class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       //line sweep
       vector<vector<int>>ans;
       vector<pair<int,int>>line_sweep;

       for(int i=0; i<intervals.size(); i++){
         int x=intervals[i][0];
         int y=intervals[i][1];
         line_sweep.push_back({x,+1});
         line_sweep.push_back({y,-1});
       } 
        line_sweep.push_back({newInterval[0],+1});
        line_sweep.push_back({newInterval[1],-1});
         
        sort(line_sweep.begin(), line_sweep.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first){
            //agar element same nhi hai to isko ascending order me kr dega
         return a.first < b.first; 
        }else{
            //iska mtlb ye hai ki agar do element ka index same hua to agar +1,-1 to ye by default return true kr dega lekin agar aisa nhi h to ye return false kr dega..iska mtlb agar -1, +1 hai to ye +1,-1 kr dega..
          return a.second > b.second;   
        }
        
    });
        int count=0;
        int temp=0;
        for(auto it:line_sweep){
           int x=it.first;
           int y=it.second;
           count+=y;
           
           if(count==1 && y>0){
             temp=it.first;
           }
           if(count==0){
            ans.push_back({temp,x});
           }
        }
        return ans;
    }
};
//same code of merge interval