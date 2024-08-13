//https://leetcode.com/problems/delete-node-in-a-bst/description/

class Solution {
public:
    int findmax(TreeNode* root, int currentMax) {
        while (root != NULL) {
            currentMax = max(currentMax, root->val);
            root = root->right;
        }
        return currentMax;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left != NULL && root->right != NULL) {
                //dekho agar dono null nhi hai to left part me se max khojo..uske baad usko replace krdo jo  key tha..
                int v = findmax(root->left, INT_MIN);
                root->val = v;//replace of key
                //uske baad jisko tm max khoja hai usko remove kr do root->left me se..kyoki wo 2 jagah hai...
                root->left = deleteNode(root->left, v);
                
            } else if (root->left != NULL) {
               return root->left;
               
               
            } else if (root->right != NULL) {
                return root->right;
                
               
            } else {
              
                return NULL;
            }
        }
        return root;
    }
};