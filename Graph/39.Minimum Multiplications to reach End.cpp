//https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end){
            return 0;
        }
        int n=arr.size();
        queue<pair<int,int>>q;
        q.push({start,0});//start,count
        
        vector<int>ans(100000,1e9);
        ans[start]=0;
        int MOD=1e5;
        while(!q.empty()){
            int node=q.front().first;
            int count=q.front().second;
            q.pop();
            for(auto it:arr){
                int curr_val=it*node%MOD;
                if(count+1<ans[curr_val]){
                    q.push({curr_val,count+1});
                    ans[curr_val]=count+1;
                     if(curr_val==end){
                        return ans[curr_val];
                    }
                }
            }
        }
        return -1;
    }
};