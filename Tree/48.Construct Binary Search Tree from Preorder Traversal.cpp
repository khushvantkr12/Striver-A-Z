//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

//TC-O(NLOG(N)+O(N)
//SC-O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end,int& idx) {
        // base case
        if (start > end) {
            return NULL;
        }

       // int start = idx;
        int x = preorder[idx];
        int rootIndex = start;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == x) {
                rootIndex = i;
                break;
            }
        }
    idx++;
        TreeNode* y = new TreeNode(x);
        y->left = solve(preorder, inorder, start, rootIndex - 1,idx);
        y->right = solve(preorder, inorder, rootIndex + 1, end,idx);
        return y;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // convert preorder into inorder
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        int idx=0;
        int n = inorder.size();
        return solve(preorder, inorder, 0, n - 1,idx);
    }
};

//TC-O(N)
//SC-O(1)

//image attach in notes section..consider for dry run
class Solution {
public:
    TreeNode* solve(vector<int>& preorder,int maxi,int& idx){
        //base
        if(idx==preorder.size() || maxi<preorder[idx]){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        //left me jaate jaao aur root->val store krte jaao...
        root->left=solve(preorder,root->val,idx);
        root->right=solve(preorder,maxi,idx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //int maxi=INT_MAX;
        int idx=0;
        return solve(preorder,INT_MAX,idx);
    }
};
//DRY RUN

//Let's walk through the dry run of the corrected code with the preorder list [8, 5, 1, 7, 10, 12].

Initial Setup:
preorder = [8, 5, 1, 7, 10, 12]
idx = 0 (starting index)
bound = INT_MAX (initial bound is the maximum integer value)
First Call to solve:
idx = 0, preorder[idx] = 8
bound = INT_MAX
Create a new TreeNode with value 8. This becomes the root.
Increment idx to 1.
Now, recursively build the left subtree with bound = 8.
Second Call to solve (Left Subtree of 8):
idx = 1, preorder[idx] = 5
bound = 8
Create a new TreeNode with value 5. This becomes the left child of 8.
Increment idx to 2.
Now, recursively build the left subtree of 5 with bound = 5.
Third Call to solve (Left Subtree of 5):
idx = 2, preorder[idx] = 1
bound = 5
Create a new TreeNode with value 1. This becomes the left child of 5.
Increment idx to 3.
Now, recursively build the left subtree of 1 with bound = 1.
Fourth Call to solve (Left Subtree of 1):
idx = 3, preorder[idx] = 7
bound = 1
Since preorder[idx] = 7 is greater than bound = 1, return nullptr.
The left child of 1 is nullptr.
Fifth Call to solve (Right Subtree of 1):
idx = 3, preorder[idx] = 7
bound = 5
Since preorder[idx] = 7 is greater than bound = 1, return nullptr.
The right child of 1 is nullptr.
Returning the TreeNode(1) back to its parent (5).
Back to the Second Call (Right Subtree of 5):
Now, we build the right subtree of 5 with bound = 8.
Sixth Call to solve (Right Subtree of 5):
idx = 3, preorder[idx] = 7
bound = 8
Create a new TreeNode with value 7. This becomes the right child of 5.
Increment idx to 4.
Now, recursively build the left subtree of 7 with bound = 7.
Seventh Call to solve (Left Subtree of 7):
idx = 4, preorder[idx] = 10
bound = 7
Since preorder[idx] = 10 is greater than bound = 7, return nullptr.
The left child of 7 is nullptr.
Eighth Call to solve (Right Subtree of 7):
idx = 4, preorder[idx] = 10
bound = 8
Since preorder[idx] = 10 is greater than bound = 8, return nullptr.
The right child of 7 is nullptr.
Returning the TreeNode(7) back to its parent (5).
Back to the First Call (Right Subtree of 8):
Now, we build the right subtree of 8 with bound = INT_MAX.
Ninth Call to solve (Right Subtree of 8):
idx = 4, preorder[idx] = 10
bound = INT_MAX
Create a new TreeNode with value 10. This becomes the right child of 8.
Increment idx to 5.
Now, recursively build the left subtree of 10 with bound = 10.
Tenth Call to solve (Left Subtree of 10):
idx = 5, preorder[idx] = 12
bound = 10
Since preorder[idx] = 12 is greater than bound = 10, return nullptr.
The left child of 10 is nullptr.
Eleventh Call to solve (Right Subtree of 10):
idx = 5, preorder[idx] = 12
bound = INT_MAX
Create a new TreeNode with value 12. This becomes the right child of 10.
Increment idx to 6.
Now, recursively build the left and right subtrees of 12. Since idx has reached the end of the array, both will return nullptr.
Returning the TreeNode(12) back to its parent (10).
Final Tree Structure:
After all recursive calls are completed, the constructed BST will be:

markdown
Copy code
       8
     /   \
    5    10
   / \     \
  1   7     12