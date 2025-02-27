//sweep line technique
//TC-O(nlogn)+O(n)+O(n)=O(nlogn)
//SC-O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
       vector<pair<int,int>>line_sweep;

       for(int i=0; i<intervals.size(); i++){
         int x=intervals[i][0];
         int y=intervals[i][1];
         line_sweep.push_back({x,+1});
         line_sweep.push_back({y,-1});
       } 
         
        sort(line_sweep.begin(), line_sweep.end(), []( pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first; //The expression a.first < b.first returns true if a.first is smaller than b.first, meaning a comes before b in the sorted array.

        return a.second > b.second;   
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