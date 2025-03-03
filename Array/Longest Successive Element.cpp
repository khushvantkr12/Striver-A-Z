//TC-O(N)
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    //make a unordered set..then check if (it-1) exist or not if exist move forward and if not that means number is starting point and check it..
    unordered_set<int>s;
    for(int i=0; i<a.size(); i++){
        s.insert(a[i]);
    }
    int maxi=INT_MIN;

    for(auto it:s){
        //it means it may be starting point then we can add the count if it breaks we maximize our count
        if(s.find(it-1)==s.end()){
           auto x=it;
           int count=1;
           while(s.find(x+1)!=s.end()){
               count++;
               x++;
           }
           maxi=max(maxi,count);
        }
        
    }
    return maxi;
}