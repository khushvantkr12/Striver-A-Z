//https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        
        int d1[4] = {0, -1, 1, 0};
        int d2[4] = {1, 0, 0, -1};
        
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            
            if(x==n-1 && y==m-1){
                return effort[n-1][m-1];
            }
            for(int i=0; i<4; i++){
                int x1=x+d1[i];
                int x2=y+d2[i];
                if(x1>=0 && x2>=0 && x1<n && x2<m){
                    int maxi=max(diff,abs(heights[x][y]-heights[x1][x2]));
                    if(maxi<effort[x1][x2]){
                        pq.push({maxi,{x1,x2}});
                        effort[x1][x2]=maxi;
                    }
                }
            }
        }
        
        
        return 0;
    }
};
