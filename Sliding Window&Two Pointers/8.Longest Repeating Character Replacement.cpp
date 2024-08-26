//https://leetcode.com/problems/longest-repeating-character-replacement/
//TC-O(2N)*26
//SC-O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0,maxf=INT_MIN;
        int n=s.size();
        int maxi=INT_MIN;
        while(j<n){
          mp[s[j]]++;
          maxf=max(maxf,mp[s[j]]);
          //hua ye ki agar (length-maxf) exceed kr gya to window shrink hoga ab agar window shrink hoga to maxf bhi change hoga..to uske liye for loop chla diye hai..taaki wo jaise jaise i shrink hoga waise hi wo bhi update hote jaae...
          while(j-i+1-maxf>k){
            mp[s[i]]--;
            maxf=0;
            //update maxf after shrinking window
            for(int k=i; k<=j; k++){
                maxf=max(maxf,mp[s[k]]);
            }
            i++;
          }
        
         maxi=max(maxi,j-i+1);
          j++;
        }
        return maxi;
    }
};