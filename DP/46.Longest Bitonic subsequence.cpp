//https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution {
public:
    int LongestBitonicSequence(int n, vector<int>& nums) {
        // Code here
        // Compute LIS from left to right and LIS from right to left, then sum and subtract -1 because of overlapping
        vector<int> dp1(n, 1);  // LIS
        vector<int> dp2(n, 1);  // LIS

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        
        for (int i = n-1; i >=0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

        
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if(dp1[i]==1 || dp2[i]==1) continue;
            maxLength = max(maxLength, dp1[i] + dp2[i] - 1);
        }

        return maxLength;
    }
};
