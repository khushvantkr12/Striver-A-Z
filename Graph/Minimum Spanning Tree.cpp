//https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         vector<bool>isMST(V,false);
         pq.push({0,0});
         int sum=0;
         
         while(!pq.empty()){
             int wt=pq.top().first;
             int node=pq.top().second;
             pq.pop();
             
             if(isMST[node]==true){
                 continue;
             }
             isMST[node]=true;
             sum+=wt;
             
             for(auto it:adj[node]){
                 int curr_wt=it[1];
                 int curr_node=it[0];
                 if(isMST[curr_node]==false){
                     pq.push({curr_wt,curr_node});
                    
                 }
             }
             
         }
         return sum;
    }
};