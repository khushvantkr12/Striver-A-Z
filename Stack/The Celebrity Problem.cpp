//brute force striver approach
//TC-O(N^2)
//SC-O(N)
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        //brute force
        int n=mat.size();
        vector<int>you_know_me(n,0);
        vector<int>i_know_you(n,0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(mat[i][j]==1){
                    i_know_you[i]++;
                    you_know_me[j]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(you_know_me[i]==n-1 && i_know_you[i]==0){
                return i;
            }
        }
        return -1;
    }
};
//optimized approach
//using stack
//TC-O(N)
//SC-O(N)

// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        //key step:
        //first push all index in stack
        //then compare two indices mat[i][j]==1 then push j otherwise push i
        //then check for that indices whether it is celebrity or not
        
         int n=mat.size();
         stack<int>st;
         for(int i=0; i<n; i++){
             st.push(i);
         }
         while(st.size()>1){
             int x=st.top();
             st.pop();
             int y=st.top();
             st.pop();
             
             if(mat[x][y]==0){
                 st.push(x);
             }else{
                 st.push(y);
             }
         }
         int celebrity=st.top();
         
         for(int i=0; i<n; i++){
             if(i==celebrity) continue;
             
             //now check when it is -1
             //mtlb agar celebrity kisko jaanta ho to wo return -1 aur maan lo koi celebrity ko na jaanata ho phir bhi -1
             if(mat[celebrity][i]==1 || mat[i][celebrity]==0){
                 return -1;
             }
         }
         return celebrity;
    }
};


//TC-O(N)
//SC-O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int top=0,down=n-1;
        
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }else{
                down--;
            }
            
        }
        if(top!=down){
            return -1;
        }
        for(int i=0; i<n; i++){
            if(top==i) continue;
            if(mat[top][i]==1 || mat[i][top]==0){
                return -1;
            }
        }
        return top;
    }
};