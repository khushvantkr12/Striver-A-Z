//https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
     //key idea is this ki..abhi jaha pe tum ho usse upar,left,aur North-West me se jo min hoga usme 1+ kr dena utna tm square bana sakte ho
       int n=matrix.size();
       int m=matrix[0].size();

      vector<vector<int>>dp(n,vector<int>(m,0));
       for(int i=0; i<m; i++){
          dp[0][i]=matrix[0][i];
        }
        for(int i=0; i<n; i++){
          dp[i][0]=matrix[i][0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==1){
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
                
            }
        }
       
       int sum=0;
       for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[0].size(); j++){
            sum+=dp[i][j];
        }
       }
       return sum;
    }
};