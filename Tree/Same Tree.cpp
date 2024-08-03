class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;  // Both nodes are null, trees are the same so far.
        }
        if (p == NULL || q == NULL) {
            return false;  // One of the nodes is null, the other isn't.
        }
        if (p->val != q->val) {
            return false;  // The values of the nodes do not match.
        }
       
       bool x=solve(p->left, q->left);
       bool y=solve(p->right, q->right);

       return x&y;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);  // Compare the two trees directly.
    }
};
