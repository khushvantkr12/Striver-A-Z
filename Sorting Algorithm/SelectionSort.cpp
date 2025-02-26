//TC-O(n^2)
//SC-O(1)
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        for(int i=0; i<=n-2; i++){
            int mini=INT_MAX;
            int idx=0;
            for(int j=i; j<=n-1; j++){
                if(arr[i]>arr[j] && mini>arr[j]){
                    mini=min(mini,arr[j]);
                    idx=j;
                }
            }
           if(mini!=INT_MAX){
               swap(arr[i],arr[idx]);
           }
        }
    }
};