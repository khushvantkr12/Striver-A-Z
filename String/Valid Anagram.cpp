class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        for (char c : t) {
            mp[c]--;
        }

        for (auto& entry : mp) {
            if (entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};