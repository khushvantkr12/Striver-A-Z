#include <bits/stdc++.h>


int partiton(vector<int>&arr,int low,int high){
     int i = low, j = high;
    int pivot = arr[low];

    while (i < j) {
        while (i < high && arr[i] <= pivot) {
            i++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Correcting pivot position
    swap(arr[low], arr[j]);

    return j;
}
void quickSortHelper(vector<int>&arr,int low,int high){
    if(low>=high){
        return;
    }

    int p=partiton(arr,low,high);
    quickSortHelper(arr,low,p-1);
    quickSortHelper(arr,p+1,high);
}
vector<int> quickSort(vector<int> arr)
{
    //step to find:
    //pick any pivot element and place that element its correct place.
    //smaller element on left and larger on right as compared to pivot.
    //after 1 step step we can say one element is at correct position
    //repeat the same..on left array as well as right array with the help of recursion
    //---pseudo code---
    //take low and high and take i=0,j=n-1..then choose pivot=arr[low]..
    //left side se mere ko ye khojna hai ki kon element pivot se bada hai jaise hi mil jaae ruk jaana hai,,same side se ye khojna hai ki kon pivot se chota hai jaise hi mile swap kr dena hai arr[i] aur arr[j] ko..
    //jb i>j ho jaae iska mtlb pivot ka correct position mil gya hai

    //code
    quickSortHelper(arr, 0, arr.size() - 1);
    return arr;

}