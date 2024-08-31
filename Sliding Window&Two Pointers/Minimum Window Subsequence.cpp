//https://www.geeksforgeeks.org/problems/minimum-window-subsequence/0

class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here
        int i=0,j=0;
        int n=s.size();
        int minWindow=INT_MAX;
        int start=-1;
        while(i<n){
        //for(int i=0;i<s.length();i++){
            // If characters are same, then increment the j pointer
            if(s[i]==t[j]){
                j++;
            }
            // If we finally reach the end of string T, we can start shrinking our window
            if(j==t.length()){
                j--;
                //taki maximum index ko store kr sake
                int end=i;
                // We are doing j-- in order to minimize our window size
                while(j>=0){
                    if(s[i]==t[j]){
                        j--;
                    }
                    i--;
                }
                 i++;
                 j++;
                
                // Incrementing i and j for next iteration
                if(end-i+1<minWindow){
                    minWindow=end-i+1;
                    start=i;
                }
                
            }
            i++;
        }
        
        return minWindow==INT_MAX?"":s.substr(start,minWindow);
        
    }
};
