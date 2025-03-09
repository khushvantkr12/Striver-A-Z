class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& a, vector<int>& d) {
        vector<pair<int,int>> l;
        for(int i: a) l.push_back({i,1});
        for(int i: d) l.push_back({i,-1});
        
        // for(int i=0; i<l.size(); i++){
        //     cout<<l[i].first<<" "<<l[i].second<<" ";
        // }cout<<endl;
        
        sort(l.begin(), l.end(), [](pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) 
        return a.first < b.first;
    return a.second > b.second;  
});

        
        // for(int i=0; i<l.size(); i++){
        //     cout<<l[i].first<<" "<<l[i].second<<" ";
        // }cout<<endl;
        
        int ans = 0, maxAns = 0;
        for(auto i: l){
            ans += i.second;
            maxAns = max(maxAns,ans);
        }
        return maxAns;
    }
};