class Solution {
public:
    int maxDepth(string s) {
        int maxi=INT_MIN;
        int count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                count++;
                maxi=max(maxi,count);
            }else if(s[i]==')'){
                count--;
            }
        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
    }
};