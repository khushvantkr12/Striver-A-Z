//push the max to last by adjacet swaps
//core idea is to do adjacent swaps on each iteration and push max to the last
//best case time complexity is O(n) and worst case time complexity is O(n^2)


class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        
        for(int i=0; i<n-1; i++){
            bool flag=true;//it checks whether the arr is sorted or not initially
            for(int j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    flag=false;
                }
            }
            if(flag==true){
                break;
            }
        }
    }
};
