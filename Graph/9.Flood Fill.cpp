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

//BFS
//TC-O(n*m)
//SC-O(n*m) in best case O(1)
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;  // Avoid infinite loops if already filled
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;  // Color the starting pixel

        int d1[4] = {-1, 1, 0, 0};  
        int d2[4] = {0, 0, -1, 1}; 

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int dx = d1[i] + x;
                int dy = d2[i] + y;

                if (dx >= 0 && dx < n && dy >= 0 && dy < m && image[dx][dy] == originalColor) {
                    q.push({dx, dy});
                    image[dx][dy] = color;  // Update color directly
                }
            }
        }

        return image;
    }
};