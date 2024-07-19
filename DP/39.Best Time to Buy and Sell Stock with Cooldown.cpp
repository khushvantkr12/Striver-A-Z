class Solution {
public:
    int solve(int idx,bool buy,vector<int>& prices,vector<vector<int>>&dp){
        //base
       if(idx>=prices.size()){
        return 0;
       }
   if(dp[idx][buy]!=-1){
    return dp[idx][buy];
   }


        int take=0,skip=0;
        if(buy){
            //2 option hai ki hum us stock ko buy kare ya abhi buy na kare
            take=-prices[idx]+solve(idx+1,0,prices,dp);//suppose hm buy kar liye hai to humko buy ko 9 karna hoga means ki next day humko sell karna hai..aisa na ho ki hum lagatar 2 din buy hi karle..aur minus kyo? to dekho tm koi cheez buy kar rhe ho iska mtlb tum paisa laga rhe ho..
            skip=solve(idx+1,1,prices,dp);
            return dp[idx][buy]=max(take,skip);
        }else{
            //phir 2 case..suppose tm koi stock buy kar liya..ab tmko man kiya ki tm us din usko becho..aur tmko man nhi ki usko us din bechne ka
            take=prices[idx]+solve(idx+2,1,prices,dp);//tm bech diya to tumko buy ko 1 karna hoga..kyoki ab tm phir kharidne ke liye ready ho..ab tm koi chiz becha hai to tumhare pass paisa aaya hai to (+) likhe hai
            skip=solve(idx+1,0,prices,dp);
            return dp[idx][buy]=max(take,skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(0,1,prices,dp);//1 yaha pe boolean hai
        vector<vector<int>>dp(n+2,vector<int>(2,0));
       
         for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][buy] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};