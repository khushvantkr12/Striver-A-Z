class Solution {
public:
    bool rotateString(string s, string goal) {
        

        for(int i=0; i<s.size(); i++){
            string ss="";
                if(i==0){
                ss+=s.substr(i,s.size());
                }else{
                    ss+=s.substr(i,s.size());
                    ss+=s.substr(0,i);
                }
                cout<<ss<<endl;
                if(ss==goal){
                    return true;
                }
        }
        return false;
    }
};