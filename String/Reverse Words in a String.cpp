//TC-O(N)
//SC-O(N)
class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = s.size() - 1;
        string ss = "";
        int count = 0;

        while (j >= 0) {  
            while (j >= 0 && s[j] == ' ') {  
                j--;
            }
            //cout<<j<<endl;
            if (j < 0) break;
            while (j >= 0 && s[j] != ' ') {  
                j--;
                count++;
            }

            if (!ss.empty()) ss += " ";  
            ss += s.substr(j + 1, count);  

            count = 0;  
        }
        
        return ss;
    }
};