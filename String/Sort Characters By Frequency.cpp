//TC-O(N)
//SC-O(N)
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        string ss="";
        for(auto it:v){
            int x=it.first;
            int y=it.second;
           for(int i=0; i<x; i++){
             ss+=y;
           }
        }
        return ss;
    }
};