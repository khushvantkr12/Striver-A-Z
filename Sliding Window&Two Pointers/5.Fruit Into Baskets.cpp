//https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution {
public:
    int totalFruits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> fruitCount;
        int i = 0, j = 0;
        int maxi = 0;
        
        while (j < n) {
            fruitCount[arr[j]]++;
            
            // Check if we have more than 2 distinct fruits
            while (fruitCount.size() > 2) {
                fruitCount[arr[i]]--;
                if (fruitCount[arr[i]] == 0) {
                    fruitCount.erase(arr[i]);
                }
                i++;
            }
            
            // Update the maximum length of the window
            maxi = max(maxi, j - i + 1);
            j++;
        }
        
        return maxi;
    }
};