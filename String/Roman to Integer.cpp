class Solution {
public:
    int romanToInt(string s) {
        //map
        map<char,int>mp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int count=0;
        for(int i=0; i<s.size()-1; i++){
            if(mp[s[i]]<mp[s[i+1]]){
                count-=mp[s[i]];
            }else{
                 count+=mp[s[i]];
            }
        }
        return count+mp[s[s.size()-1]];
    }
};