https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
class Solution {
  public:
    int dp[100001][3];
    //There are 2 choices dependent on the previous choice we have picked, if we picked 0, so we can pick only 1 and 2 in next round, and similarly for other choices as well
    int solve(int index, vector<vector<int>>& points, int choice){
        if(index >= points.size()) return 0;
        
        if(dp[index][choice] != -1) return dp[index][choice];
        if(choice == 0){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 1), solve(index + 1, points, 2));
        }
        else if(choice == 1){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 0), solve(index + 1, points, 2));
        }
        else if(choice == 2){
            return dp[index][choice] = points[index][choice] +
            max(solve(index + 1, points, 0), solve(index + 1, points, 1));
        }
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp, -1, sizeof(dp));
       int x=solve(0, points, 0);
       int y=solve(0, points, 1);
       int z=solve(0, points, 2);
       return max({x,y,z});
    }
};
