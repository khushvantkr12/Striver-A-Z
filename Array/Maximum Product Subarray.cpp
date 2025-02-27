class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int prod=1;
        //for going left to right
        for(int i=0; i<nums.size(); i++){
            prod*=nums[i];
            maxi=max(maxi,prod);
            if(prod==0){
                prod=1;
            }
        }
        int ans=1;
//for going right to left
        for(int i=nums.size()-1; i>=0; i--){
            ans*=nums[i];
            maxi=max(maxi,ans);
            if(ans==0){
                ans=1;
            }
        }
        return maxi;
    }
};