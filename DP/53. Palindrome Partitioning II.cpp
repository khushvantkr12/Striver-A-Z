//https://leetcode.com/problems/palindrome-partitioning-ii/description/

class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i< j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int n, string& s, vector<int>& dp) {
        // base case
       
        if(i>=n){
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int mini = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(i, k, s)) {
                int count = 1 + solve(k+1 , n, s, dp);
                mini = min(mini, count);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        //vector<int> dp(n, -1);
        //return solve(0, n, s, dp)-1;
        vector<int> dp(n+1, 0);
         
        
        for(int i=n-1; i>=0; i--){
            int mini=INT_MAX;
            for(int k=i; k<n; k++){
               if (isPalindrome(i, k, s)) {
                int count = 1 + dp[k+1];
                mini = min(mini, count);
            }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};
