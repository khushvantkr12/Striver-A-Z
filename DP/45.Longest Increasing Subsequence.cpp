//https://leetcode.com/problems/longest-string-chain/description/

class Solution {
public:
//COMPARATOR->it sorts string on the basis of their size
    void sortStringsByLength(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
    }
   //MEMOIZATION
    int solve(int prev, int idx, vector<string>& words, vector<vector<int>>& dp) {
        if (idx >= words.size()) {
            return 0;
        }

        if (dp[prev + 1][idx] != -1) {
            return dp[prev + 1][idx];
        }

        int take = 0;
        if (prev == -1 || (words[prev].size() + 1 == words[idx].size())) {
            //important condition
            if (prev == -1) {
                take = 1 + solve(idx, idx + 1, words, dp);
            }
             else {
                int i = 0, j = 0;
                while (i < words[prev].size() && j < words[idx].size()) {
                    if (words[prev][i] == words[idx][j]) {
                        i++;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
                if (i == words[prev].size()) {
                    take = 1 + solve(idx, idx + 1, words, dp);
                }
            }
        }

        int skip = solve(prev, idx + 1, words, dp);
        dp[prev + 1][idx] = max(take, skip);
        return dp[prev + 1][idx];
    }

    int longestStrChain(vector<string>& words) {
        sortStringsByLength(words);
        int n = words.size();
        //vector<vector<int>> dp(n + 1, vector<int>(n+1, -1));
        //return solve(-1, 0, words, dp);
        
        //Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));
        //no need to write base case

        for (int i = n - 1; i >= 0; i--) {
          for (int j = i - 1; j >= -1; j--) {
            int take = 0, skip = 0;
            if (j == -1 || 1 + words[j].size() == words[i].size()) {
                if (j == -1) {
                    take = 1 + dp[i + 1][i + 1];
                } else {
                    int k = 0, l = 0;
                    while (k < words[j].size() && l < words[i].size()) {
                        if (words[j][k] == words[i][l]) {
                            k++;
                        }
                        l++;
                    }
                    if (k == words[j].size()) {
                        take = 1 + dp[i + 1][i + 1];
                    }
                }
            }
            skip = dp[i + 1][j + 1];
            dp[i][j + 1] = max(take, skip);
        }
    }

    return dp[0][0];
}
};