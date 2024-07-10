//https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>temp(n+1,vector<int>(n+1,1e9));

        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            temp[u][v]=w;
            temp[v][u]=w;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    temp[i][j]=0;
                }
            }
        }
        //floyd warshall
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    temp[i][j]=min(temp[i][j],temp[i][via]+temp[via][j]);
                }
            }
        }
    //   for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //       cout<<temp[i][j]<<" ";
    //     }
    //     cout<<endl;
    //   }
     int ans=INT_MAX,res;
     vector<int> reachableCount(n, 0);
        for (int i = 0; i < n; i++) {
            int count=0;
            for (int j = 0; j < n; j++) {
                if (i != j && temp[i][j] <= distanceThreshold) {
                    count++;
                   
                }
            }
        if(count<=ans){
            ans=count;
            res=max(res,i);
        }
        }

       
       

        return res;
    }
};