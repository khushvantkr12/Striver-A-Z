
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int, int> mp;
        mp[0] = -1;  
        int sum = 0, maxi = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (mp.find(sum - k) != mp.end()) {  
                maxi = max(maxi, i - mp[sum - k]);  // Corrected indexing
            }
            // Store first occurrence only (to get the longest subarray)
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return maxi;
    }
};
