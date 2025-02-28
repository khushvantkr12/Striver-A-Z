class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        //sign represents value obtained is positive or negative
        int sign = 1;
        long result = 0;

        //condition-1
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        //check condition-2
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        //condition-3
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');//s[i]-'0' converts string integer's("3") into integer(3)
            
            //condition-4
            if (result > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }

        return result*sign;
    }
};