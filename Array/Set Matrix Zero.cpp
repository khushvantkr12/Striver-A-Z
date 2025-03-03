//TC-O(N*M*(N+M))
//SC-O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    //set entire column -1 except 0
                    for(int k=0; k<n; k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=-1e9;
                        }
                    }
                    //set entire row -1 except 0
                    for(int l=0; l<m; l++){
                        if(matrix[i][l]!=0){
                            matrix[i][l]=-1e9;
                        }
                    }
                }
            }
        }
        //jisko -1 kiya tha usko wapas 0 krdo
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==-1e9){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

