class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int>temp;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i]==arr[i+1]){
                temp.push_back(arr[i]);
                break;
            }
        }
        
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1]-arr[i]==2){
                temp.push_back(arr[i]+1);
                break;
            }
        }
        if(arr[0]!=1){
            temp.push_back(1);
        }
        if(arr[arr.size()-1]!=arr.size()){
            temp.push_back(arr.size());
        }
        return temp;
    }
};