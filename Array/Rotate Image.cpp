class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //keep it simple
        //first take transpose then reverse it along rows thats it
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=i; j<m; j++){
                //take transpose
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    }
};