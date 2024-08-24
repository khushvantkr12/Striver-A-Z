//https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (nums[j] == 0) {
                k--;
            }
            
            while (k < 0) { // Adjust window if k is negative
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            
            // Calculate the maximum length
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};