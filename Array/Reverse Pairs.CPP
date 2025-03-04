//TC-O(NLOGN)
//SC-O(N)
//THIS QUESTION IS EXACTLY SAME AS COUNT INVERSIONS JUST CHANGE THE CONDITION IN LINE 11 {nums[i] > nums[j]}
class Solution {
public:
    int solve(vector<int>& nums, int l, int mid, int r) {
        int count = 0;
        int j = mid + 1;

        for (int i = l; i <= mid; i++) {
            while (j <= r && nums[i] > 2LL*nums[j]) {
                j++;
            }
            count += (j - mid -1);  
        }
        return count;
    }

    void mergesort(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp;
        int start = l, middle = mid + 1;

        while (start <= mid && middle <= r) {
            if (nums[start] <= nums[middle]) {
                temp.push_back(nums[start]);
                start++;
            } else {
                temp.push_back(nums[middle]);
                middle++;
            }
        }

        while (start <= mid) {
            temp.push_back(nums[start]);
             start++;
        }
        while (middle <= r) {
            temp.push_back(nums[middle]);
             middle++;
        }

        for (int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }
    }

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;  // Fixed base condition

        int mid = (l + r) / 2;
        int final_count = 0;

    //   //split left part
    //   merge(nums,l,mid);
    //   //split right part
    //   merge(nums,mid+1,r);
        final_count=merge(nums,l,mid)+merge(nums,mid+1,r);
        final_count += solve(nums, l, mid, r);
        mergesort(nums, l, mid, r);

        return final_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge(nums, 0, n - 1);
    }
};
