//https://leetcode.com/problems/generate-parentheses/description/

// TC-O(2^(2*n))
// SC-O(N)
class Solution {
public:
    void solve(int n,int i,int j,string ss,vector<string>&s){
        //base
        if(i==n && j==n){
            s.push_back(ss);
            return;
        }
        if(i>n || j>n){
            return;
        }


        if(i>j){
            //2case
             //if you pass ss by reference then you write this
            //ss.push_back("(") and write pop_back also..but if you pass by value then see line 22
            solve(n,i+1,j,ss+"(",s);
            solve(n,i,j+1,ss+")",s);
        }
        if(i==j && i<n && j<n){
           solve(n,i+1,j,ss+"(",s);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        solve(n,0,0,"",s);
        return s;
    }
};