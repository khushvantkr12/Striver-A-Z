// Approach : XOR Trick (O(n) Time, O(1) Space) (Optimal Solution) 🚀
// Explanation:
// We use bitwise XOR (^) to eliminate duplicate elements and find the unique number.

// 🔹 XOR properties:

// a ^ a = 0 (same numbers cancel out)
// a ^ 0 = a (XOR with zero gives the number itself)
// a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans^=nums[i];
        return ans;
    }
};