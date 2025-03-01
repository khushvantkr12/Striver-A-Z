bool f(int ind, vector<int> &a, int k, vector<vector<int>> &dp) {
    if (k == 0) return true;
    if (k < 0 || ind >= a.size()) return false;

    if (dp[ind][k] != -1) return dp[ind][k];

    // Not take the current element
    bool skip = f(ind + 1, a, k, dp);

    // Take the current element
    bool take = false;
    if (a[ind] <= k) {
        take = f(ind + 1, a, k - a[ind], dp);
    }

    return dp[ind][k] = (take + skip);
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(0, a, k, dp);
}

 