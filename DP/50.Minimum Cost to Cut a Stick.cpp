//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution {
public:
    int solve(int i,int j,vector<int>& cuts, vector<vector<int>>&dp){
        //base
        //suppose [0,1] i on 0 and j on 1 then base case is j-i==1 then return 0
        if(j-i==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j]; 
        }
        int mini=INT_MAX;
        for(int k=i+1; k<=j-1; k++){
            int costs=0;
            costs=cuts[j]-cuts[i]+solve(i,k,cuts,dp)+solve(k,j,cuts,dp);
            mini=min(mini,costs);

        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        //lets underrstand why we insert 0 and n in cuts..becz we have to calculate length so if we add 0 and n then easily calculate..say n=7..so after first cut costs=cuts[last]-cuts[0]...aafterwards recursion will solve
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();
        //vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
         //return solve(0 ,m-1,cuts,dp);

          vector<std::vector<long long>> dp(m+2, std::vector<long long>(m+2, 0));
          for (int i = m; i >= 0; --i) {
            for (int j = i + 2; j <= m-1; ++j) {
                long long mini = LLONG_MAX;
                for (int k = i + 1; k <= j-1; ++k) {
                    long long costs = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    mini = std::min(mini, costs);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[0][m - 1];
    }
};