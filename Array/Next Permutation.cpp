//TC-O(N)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        //do 3 things 
        //step1->find just smaller element from last
        //step2->from last find which is just greater and swap them
        //step3->then reverse element just after i+1
      
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }
        //suppose [5,4,3,2,1] then i=0
        // Step 2: If found, find the next larger element and swap
        
        if (i >= 0) {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};