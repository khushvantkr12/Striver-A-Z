class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
       int i = 0, j = 0;
        vector<int> result;
        
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                if(result.size() == 0 || result.back() != a[i]){
                    result.push_back(a[i]);
                }
                i++;
            }else{
                if(result.size() == 0 || result.back() != b[j]){
                    result.push_back(b[j]);
                }
                j++;
            }
        }
        
        
        // Put here Remaining element for arr1
        while(i < a.size()){
            if(result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }
        
        
        // Put here Remaining element for arr2
        while(j < b.size()){
            if(result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }
        
        return result;
        
    }
};