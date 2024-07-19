class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
     int j=i+1;
     int maxprofit=0;
     while(i<prices.size() && j<prices.size())   
     {
           
           if(prices[i]<prices[j]) 
           {
               int ans=prices[j]-prices[i];
                maxprofit=max(maxprofit,ans);
                 j++;
           }
           else
           {
               i=j;
               j=i+1;
           }
          

     }
    return maxprofit;
    }
};