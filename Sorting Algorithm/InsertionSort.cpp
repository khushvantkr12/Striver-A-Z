//algorithm says that we have to insert the element in the correct position
// Steps:
// Start with the second element (index 1).
// Compare it with the previous elements and shift larger elements one position to the right.
// Insert the current element into its correct position.
// Repeat for all elements in the array.

class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=0; i<=n-1; i++){
            int j=i;
            while(j>0 && arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                j--;
            }
        }
    }
};
