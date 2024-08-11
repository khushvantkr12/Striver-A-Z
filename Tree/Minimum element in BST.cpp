class Solution {
  public:
    int solve(Node* root){
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL){
            return root->data;
        }
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        solve(root->left);
    }
    int minValue(Node* root) {
        // Code here
        return solve(root);
    }
};
