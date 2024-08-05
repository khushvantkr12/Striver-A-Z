//https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

class Solution {
public:
    void solve(Node* root, vector<int>& temp, vector<vector<int>>& ans) {
        // base case
        if (root == NULL) {
            return;
        }
        
         
       temp.push_back(root->data);
       if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
        }
       else {
           
            solve(root->left, temp, ans);
            solve(root->right, temp, ans);
        }
       
        temp.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root, temp, ans);
        return ans;
    }
};
