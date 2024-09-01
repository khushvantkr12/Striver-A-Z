//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
//TC-O(K)+O(K)=O(2K)
//SC-O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {  
        int sum1=0;
        for(int i=0; i<k; i++){
            sum1+=cardPoints[i];
        }
        int maxi=sum1;
        int n=cardPoints.size();
        int i=k-1,j=n-1;
        while(i>=0 ){
           sum1-=cardPoints[i];
           sum1+=cardPoints[j];

           if(sum1>maxi){
            maxi=sum1;
           }
           i--;
            j--;
        }
        
   return maxi;
    }
};
