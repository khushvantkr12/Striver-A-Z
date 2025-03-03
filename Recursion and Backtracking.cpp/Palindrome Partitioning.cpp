//TC-O(N*2^N) SC-O(n^2)
class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, string &s, vector<vector<string>> &ans, vector<string> &temp) {

        if (i == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(i, j, s)) {  
                string ss = s.substr(i, j - i + 1); 
                temp.push_back(ss);
                solve(j + 1, s, ans, temp); // Move to the next substring
                temp.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, temp);
        return ans;
    }
};





Let's do a dry run for s = "abba" using the corrected code.

Step 1: Initial Call
scss
Copy
Edit
solve(0, "abba", ans, temp)
i = 0, temp = []
Loop over j (0 to 3).
Step 2: Checking Palindromes
(1st Iteration: i=0, j=0 → "a")
"a" is a palindrome.
Add "a" to temp:
temp = ["a"]
Recursive call:
solve(1, "abba", ans, temp)
Step 3: Second Level Calls
(1st Iteration: i=1, j=1 → "b")
"b" is a palindrome.
Add "b" to temp:
temp = ["a", "b"]
Recursive call:
solve(2, "abba", ans, temp)
Step 4: Third Level Calls
(1st Iteration: i=2, j=2 → "b")
"b" is a palindrome.
Add "b" to temp:
temp = ["a", "b", "b"]
Recursive call:
solve(3, "abba", ans, temp)
Step 5: Fourth Level Calls
(1st Iteration: i=3, j=3 → "a")
"a" is a palindrome.
Add "a" to temp:
temp = ["a", "b", "b", "a"]
Recursive call:
solve(4, "abba", ans, temp)
Step 6: Base Case Reached
i = 4 (End of string)
Add ["a", "b", "b", "a"] to ans
Backtrack (remove "a" from temp)
Step 7: Backtracking
Back to i=3, j=3
Backtrack "b"
temp = ["a", "b", "b"]
Backtrack "b"
temp = ["a", "b"]
(Checking i=1, j=2 → "bb")
"bb" is a palindrome.
Add "bb" to temp:
temp = ["a", "bb"]
Recursive call:
solve(3, "abba", ans, temp)
Step 8: Continuing
(i=3, j=3 → "a")
"a" is a palindrome.

Add "a" to temp:
temp = ["a", "bb", "a"]

Recursive call:
solve(4, "abba", ans, temp)

Base Case: Add ["a", "bb", "a"] to ans

Backtrack

Step 9: Backtracking
temp = ["a"]

Check i=0, j=3 → "abba"

"abba" is a palindrome.

Add "abba" to temp:
temp = ["abba"]

Recursive call:
solve(4, "abba", ans, temp)

Base Case: Add ["abba"] to ans

Backtrack

Final Answer:
arduino
Copy
Edit
[
  ["a", "b", "b", "a"],
  ["a", "bb", "a"],
  ["abba"]
]
🚀 Summary:

We explored all possible partitions recursively.
We backtracked correctly to explore different partitions.
The answer contains all possible valid palindrome partitions. ✅






