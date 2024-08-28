//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

//TC-O(N)
//SC-O(1)//BECAUSE MAP stores only 3 character..
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<char,int>mp;
        int i=0,j=0,result=0,prevcount=0;

        while(j<n){
          mp[s[j]]++;

        while(mp.size()==3){
            prevcount++;
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }

          result+=prevcount;
          j++;
        }
        return result;
    }
};