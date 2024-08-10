
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //using morris traversal
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the rightmost node in the left subtree or the predecessor
                TreeNode* temp = curr->left;  // Start with the left child

                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                   
                     ans.push_back(curr->val);
                    temp->right = curr;
                    curr = curr->left;
                } else {
                   
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    
    }
};