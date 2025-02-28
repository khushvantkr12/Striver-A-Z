class Solution {
  public:
    int countSubstrAtMostK(string& s, int k){
        unordered_map<char, int> freq;
        int left = 0;
        int count = 0;
        
        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;
            
            // If current window exceeds k, reduce window size
            while(freq.size() > k){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            
            count += right - left + 1; // To count all substrings ending at right.
        }
        
        return count;
    }
  
    int countSubstr(string& s, int k) {
        // Intuition -> substrs with EXACTLY k dist chars = substrs with ATMOST k dist chars - substrs with ATMOST k-1 dist chars.
        
        return countSubstrAtMostK(s, k) - countSubstrAtMostK(s, k-1);
    }
};
