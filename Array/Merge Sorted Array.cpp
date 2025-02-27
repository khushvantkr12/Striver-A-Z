class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int>temp;
        while(i<m && j<n){
          if(nums1[i]<nums2[j]){
            temp.push_back(nums1[i]);
             i++;
          }else{
            temp.push_back(nums2[j]);
            j++;
          }
        }
        while(j<n){
            temp.push_back(nums2[j]);
            j++;
        }
        while(i<m){
            temp.push_back(nums1[i]);
            i++;
        }
        // for(int i=0; i<temp.size(); i++){
        //     cout<<temp[i]<<" ";
        // }
        for(int k=0; k<temp.size(); k++){
            nums1[k]=temp[k];
        }
    }
};

//without extra space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Last valid element in nums1
    int j = n - 1; // Last element in nums2
    int k = m + n - 1; // Last index of nums1

    // Merge nums1 and nums2 from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--]; // Place the larger element at the end
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If elements are left in nums2, copy them (nums1 is already in place)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
    }
};