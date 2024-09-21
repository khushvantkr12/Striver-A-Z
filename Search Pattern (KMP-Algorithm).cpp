//https://www.geeksforgeeks.org/problems/search-pattern0205/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//TC-O(M+N)
//SC-O(M)
class Solution
{
public:
    void solve(string pattern, int n, vector<int>& LPS) {
        LPS[0] = 0;  // Length of the longest proper prefix which is also suffix for index 0 is always 0
        int length = 0;  // Length of the previous longest prefix suffix
        int j = 1;
        while (j < n) {
            if (pattern[j] == pattern[length]) {
                length++;
                LPS[j] = length;
                j++;
            } else {
                if (length != 0) {
                    length = LPS[length - 1];  // Try to find the next longest prefix suffix
                } else {
                    LPS[j] = 0;
                    j++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt) {
        int n = pat.size();
        int m = txt.size();
        
        vector<int> LPS(n, 0);
        solve(pat, n, LPS);
        vector<int> ans;
        
        int i = 0, j = 0;
        while (j < m) {
            if (pat[i] == txt[j]) {
                i++;
                j++;
            }

            if (i == n) {  // Match found
                ans.push_back(j - i + 1);  // Store the starting index (1-based index)
                i = LPS[i - 1];
            } else if (j < m && pat[i] != txt[j]) {  // Mismatch after i matches
                if (i != 0) {
                    i = LPS[i - 1];
                } else {
                    j++;
                }
            }
        }
        
        return ans;
    }
};