//https://www.geeksforgeeks.org/problems/topological-sort/1


class Solution
{
	public:
	
    void dfs(int u,vector<int> adj[],vector<bool>&visited,stack<int>&st){
        visited[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        
        //pahle mere baccho ko push karo phir mujhe..v->u..to pahle u hoga uske baad v
        //1->{2,3} to pahle stack me push 2,3 hoga phir 1 hoga
        st.push(u);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>visited(V,false);
	    stack<int>st;
	    for(int i=0; i<V; i++){
	       if(!visited[i]){
	           dfs(i,adj,visited,st);
	       }
	    }
	   vector<int>ans;
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}
};