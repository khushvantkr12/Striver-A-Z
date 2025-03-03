//TC-O(N^2)
class Solution {
public:
    vector<int> dp; 
    
    bool solve(int i, string &s, unordered_set<string>& st) {
        if (i == s.size()) return true; 

        if (dp[i] != -1) return dp[i];  

        for (int j = i; j < s.size(); j++) {
            string y = s.substr(i, j - i + 1);
            if (st.find(y) != st.end()) {
                // If valid word found, move to the next index
                if(solve(j + 1, s, st)){
                   return dp[i] = true;
                }
               
            }
        }
        return dp[i] = false; 
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp.resize(s.size(), -1);
        return solve(0, s, st);
    }
};