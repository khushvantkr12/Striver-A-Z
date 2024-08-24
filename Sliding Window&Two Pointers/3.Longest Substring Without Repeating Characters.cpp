//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
      
      
        map<char,int>mp;
        int n=s.size();
        int maxi=0;
        int i=0,j=0;
        
        while(j<n){
            mp[s[j]]++;

            if(mp[s[j]]>1){
               
                while(s[i]!=s[j]){
                    i++;
                }
                mp[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
     return maxi;
    }
};
