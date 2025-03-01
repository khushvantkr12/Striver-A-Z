//https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution{
public:
    void solve(int num,int i,string ss,vector<string>&s){
        //base
        if(i==num){
            s.push_back(ss);
            return;
        }
        if(i>num){
            return;
        }


        if(i<num && i==0){
            //2case
             //if you pass ss by reference then you write this
            //ss.push_back("(") and write pop_back also..but if you pass by value then see line 22
            solve(num,i+1,ss+"0",s);
            solve(num,i+1,ss+"1",s);
            
        }
       else if(i<num && ss[i-1]!='1'){
           solve(num,i+1,ss+"0",s);
            solve(num,i+1,ss+"1",s);
            
        }
        else {
            solve(num,i+1,ss+"0",s);
        }
        
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>s;
        solve(num,0,"",s);
        return s;
    }
};