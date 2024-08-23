//https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void dfs(int u,int v,vector<vector<int>>& image,int color,int img,int n,int m){
        //base
      if(u<0 || u>=n || v<0 || v>=m || image[u][v]==color || image[u][v]!=img){
        return ;
      }
     image[u][v]=color;


        
            dfs(u+1,v,image,color,img,n,m);
            dfs(u,v+1,image,color,img,n,m);
            dfs(u-1,v,image,color,img,n,m);
            dfs(u,v-1,image,color,img,n,m);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
            if(i==sr && j==sc){
                dfs(i,j,image,color,image[sr][sc],n,m);
            }
          }
        }
        return image;
    }
};