//https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution{
    set<string> res;
public:
    void gen(string s,int num,int c){
        if(c==num){
            res.insert(s);
            return;
        }
        if(s[c-1] == '1'){
        gen(s+'0',num,c+1);
        }
        if(s[c-1]!='1'){
            gen(s+'0',num,c+1);
            gen(s+'1',num,c+1);
        }
    }
    vector<string> generateBinaryStrings(int num){
        gen("0",num,1);    
        gen("1",num,1);  
        
        vector<string> ans;
        for(auto i:res){
            ans.push_back(i);
        }
        return ans;
    }
};