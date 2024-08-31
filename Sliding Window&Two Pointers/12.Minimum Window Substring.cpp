//https://leetcode.com/problems/minimum-window-substring/
//TC-O(2N)+O(M)
//SC-O(256)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) {
            return "";
        }

        map<char, int> mp1, mp2;
        for (int i = 0; i < m; i++) {
            mp1[t[i]]++;
        }

        int count = 0, minLength = INT_MAX, start = 0, i = 0, j = 0;

        while (j < n) {
           if(mp1.find(s[j])!=mp1.end()){
             mp2[s[j]]++;
             if(mp2[s[j]]<=mp1[s[j]]){
                count++;
             }
           }

            while (count == m) {
                if (j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    start = i;
                }
                if (mp1.find(s[i]) != mp1.end()) {
                    mp2[s[i]]--;
                    if (mp2[s[i]] < mp1[s[i]]) {
                        count--;
                    }
                }
                i++;
            }
            j++;
        }

        if (minLength == INT_MAX) {
            return "";
        }
        return s.substr(start, minLength);
    }
};
