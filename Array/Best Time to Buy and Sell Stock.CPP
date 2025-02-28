class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min1=INT_MAX;
        int max1=0;
        for(int i=0;i<prices.size();i++){
        min1 = min(min1, prices[i]);
        max1 = max(max1, prices[i] - min1);
        }
        return max1;
    }
};