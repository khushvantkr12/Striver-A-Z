//https://leetcode.com/problems/n-queens/description/
//TC-O(n! * n)-->n is for check function,,,n! for backtracking
//SC-O(n^2)
class Solution {
public:
    bool check(int x, int y,vector<vector<char>>&grid,vector<vector<string>>&ans,int n){
        //base
        //check for column
        for(int i=0; i<x; i++){
            if(grid[i][y]=='Q'){
                return false;
            }
        }
        int i = x - 1, j = y - 1;
        while (i >=0 && j >=0) {
            if (grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // Check top-right diagonal
        i = x - 1, j = y + 1;
        while (i >= 0 && j < n) {
            if (grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
         
        return true;
    }
    void solve(int row,vector<vector<char>>&grid, vector<vector<string>>&ans,int n){
        //base
        //convert grid element into ans vector..
     if(row==n){
        vector<string>temp;
        for(int i=0; i<n; i++){
            string str="";
            for(int j=0; j<n; j++){
             str+=grid[i][j];
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
        return;
     }

        for(int col=0;col<n; col++){
          if(check(row,col,grid,ans,n)){
             grid[row][col]='Q';
             solve(row+1,grid,ans,n);
          }
          grid[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        vector<vector<string>>ans;

        solve(0,grid,ans,n);//0-->row
        return ans;
    }
};