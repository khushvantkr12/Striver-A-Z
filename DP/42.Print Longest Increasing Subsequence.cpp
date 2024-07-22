//https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
         vector<int>dp(n,1);
       //isme hm ye store karenge ki suppose dp[3]=4..iska mtlb 4 length ka longest increasing mila..to ans[3] me hum index store karenge uska jisne dp[3] ko 4 banaya..mtlb last index store karenge isme.. 
       vector<int>prev_index(n,-1);
       
        int max_length = 1;
        int max_index = 0;

        // Build the dp and prev_index arrays
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i]>arr[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev_index[i] = j;
                }
            }
            //tmko largest value ka track rakhna hai..
            if (dp[i] > max_length) {
                max_length = dp[i];
                max_index = i;
            }
        }
         vector<int> result;
        for (int i = max_index; i >= 0; i = prev_index[i]) {
            result.push_back(arr[i]);
            if (prev_index[i] == -1) break;
        }

        reverse(result.begin(), result.end());
      
      return result;
    }
};