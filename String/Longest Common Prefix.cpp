class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> mp;

        if (strs.size() == 1) {
            return strs[0];
        }

        // Store all possible prefixes in map
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 1; j <= strs[i].size(); j++) { 
                string ss = strs[i].substr(0, j);
                mp[ss]++;
            }
        }

        string final = "";
        int maxi = 0; 
        
        for (auto it : mp) {
            if (it.second == strs.size()) {  
                if (it.first.size() > maxi) {  
                    maxi = it.first.size();
                    final = it.first;
                }
            }
        }

        return final;
    }
};