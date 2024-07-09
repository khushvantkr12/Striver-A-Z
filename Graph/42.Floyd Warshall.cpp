//https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	   for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1)
	                matrix[i][j]=1e9;
	            }
	        }
	        
	        for(int via=0; via<n; via++){
	            for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
	        }
	            }
	    }
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	           if(matrix[i][j]==1e9)
	                matrix[i][j]=-1;
	            } 
	        }
	    
	}
};

// why we take this  for(int i=0; i<n; i++){
// 	        for(int j=0; j<n; j++){
// 	            if(matrix[i][j]==-1)
// 	                matrix[i][j]=1e9;
// 	            }
// 	        }

//ANS:
In the adjacency matrix matrix, an entry matrix[i][j] = -1
indicates that there is no direct edge between nodes i and j.
However, the algorithm works by iteratively updating the shortest path distances,
and it requires that non-existent edges be represented by a large value
(effectively "infinity") so that they do not interfere with the minimum path
calculations.

Algorithm Execution: Now, the algorithm can correctly compute the shortest paths
without being misled by the -1 values. If -1 were left as is, it could incorrectly
suggest shorter paths than actually exist. The large value effectively means
"no path."

Reverting Large Values Back to -1: After the algorithm completes,
 paths that remain as 1e9 indicate there was no possible path between those nodes.
  These are reverted back to -1 to signify no connection.