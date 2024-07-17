//https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
   bool solve(int i,int j,string& s, string& p, vector<vector<int>> &dp){
    //base
    //MEMOIZATION
    //T.C-O(N*M)
    //S.C-O(N*M)+O(N+M)-->auxillary stack space

    if(i==s.size()&&j==p.size()){
        return true;
    }
     if(i<s.size()&&j>=p.size()){
        return false;
    }
    //imp base case now
    if(i==s.size() && j<p.size()){
       //dekho yaha pe hoskta hai p="***" ye ho ya fir p="**b" aisa kuch ho skta hai..to yaha pe loop chalana hoga
       for(int k=j; k<p.size(); k++){
         if(p[k]!='*'){
            return false;
         }
       }
       return true;
    }
     if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i]!=p[j]&&p[j]=='*'){
        //2 case
        int takeone=solve(i,j+1,s,p,dp);
        int takenull=solve(i+1,j,s,p,dp);
        return dp[i][j]=takeone||takenull;
    }
    if(s[i]==p[j]||p[j]=='?'){
        return dp[i][j]=solve(i+1,j+1,s,p,dp);
    }
    //agar koi character s aur p me match nhi kiya to
    return dp[i][j]=false;
   }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        //vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        //return solve(0,0,s,p,dp);

        //TABULATION
        //T.C-O(N*M)
        //S.C-O(N*M)
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
         //base case
         dp[n][m]=true;//empty pattern matches any string
          
         for(int i=0; i<m; i++){	
			for(int k=i;k<m;k++){
				if(p[k]!='*'){
                    dp[n][i]=false;
					break;//if i not apply break here then loop is continue iterating and if it finds "*" then it mark true;agar break nhi use karenge to ye suppose "*a*b" to ye a ke baad star hai na usko true mark kar dega..jbki isko jaise hi character mila turant break kr jaana hai..aage jaane ka koi jarurat nhi hai
				}else{
                  dp[n][i]=true;
                }
			}
		}

         for(int i=0; i<n; i++){
            dp[i][m]=false;
         }
         
         for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i]!=p[j]&&p[j]=='*'){
                   dp[i][j]=dp[i+1][j]||dp[i][j+1];
                }
               else if(s[i]==p[j]||p[j]=='?'){
                 dp[i][j]=dp[i+1][j+1];
    }
             else {
                dp[i][j]=false;
               }
            }
         }
        //  for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         cout<<dp[i][j]<<" "; 
        //     }cout<<endl;
        //  }
         return dp[0][0];
    }
};