//https://www.naukri.com/code360/problems/distinct-characters_2221410

#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int i = 0, j = 0;
    int maxi = 0;
    int n = str.size();
    map<char, int> mp;

    while (j < n) {
        mp[str[j]]++;
        
        // Shrink the window until we have at most 'k' distinct characters
        while (mp.size() > k) {
            mp[str[i]]--;
            if (mp[str[i]] == 0) {
                mp.erase(str[i]);
            }
            i++;
        }
        

        maxi = max(maxi, j - i + 1);
        j++;
    }

    return maxi;
}
