//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution {
public:
    void flatten(TreeNode* root) {
      
        while(root!=NULL){
            if(root->left==NULL){
               root=root->right;
            }else{
                TreeNode* temp=root->left;
                while(temp->right){
                  temp=temp->right;
                }
                temp->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;

            }
        }
        return ;
    }
};
//refer to rohit negi