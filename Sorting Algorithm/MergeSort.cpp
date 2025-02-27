//TC-O(nlogn)
//SC-O(n)
//approach:
//1. we have to divide the array into two parts and sort them
//2. then merge them
//3. we have to do this recursively

class Solution {
  public:
  
   void merge(vector<int>& arr, int l, int r,int mid){
       //base
       vector<int>temp;

       int left=l,right=mid+1,high=r;
       while(left<=mid && right<=high){
           if(left<=mid && arr[left]<=arr[right]){
               temp.push_back(arr[left]);
               left++;
           }else if(right<=high && arr[left]>arr[right]){
               temp.push_back(arr[right]);
               right++;
           }
       }
       while(right<=high){
           temp.push_back(arr[right]);
           right++;
       }
        while(left<=mid){
           temp.push_back(arr[left]);
           left++;
       }
      
   //copying the temp array to original array
    for (int i = l; i <= r; i++) {
            arr[i] = temp[i-l];
        }
    //     for(int i=0; i<temp.size(); i++){
    //       cout<<temp[i]<<" ";
    //   }cout<<endl;
   }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
       if(l>=r){
           return;
       }
       int mid=(l+r)/2;
       //first it sort left part
       mergeSort(arr,l,mid);
       //then it sort right part
       mergeSort(arr,mid+1,r);
       //then merge all of them
       merge(arr,l,r,mid);
       
       
    }
};
