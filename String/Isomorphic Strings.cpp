class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // TC : 0(n) , SC : 0(n)

        if(s.size()!=t.size()) return false;

        map<char,vector<int>>m1;
        map<char,vector<int>>m2;

        for(int i=0;i<s.size();i++){
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);
            
            if(m1[s[i]]!=m2[t[i]]) return false;
        }
        return true;
    }
};