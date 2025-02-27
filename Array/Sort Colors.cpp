//TC-O(N)
//SC-O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //DUTCH NATIONAL FLAG ALGORITHM
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
               //dude just swap with low 
               swap(nums[low],nums[mid]);
               mid++;
               low++;
            }
            else if(nums[mid]==1){
               //kuch nhi krna hai
               mid++;
            }
            else if(nums[mid]==2){
              //JUST SWAP WITH HIGH
              swap(nums[mid],nums[high]);
              high--;

            }
        }
    }
};