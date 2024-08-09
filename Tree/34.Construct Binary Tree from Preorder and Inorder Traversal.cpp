//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        // Base case
        if (start > end) {
            return NULL;
        }
        
        int currVal = preorder[idx];
        int j = start;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == currVal) {
                j = i;
                break; // We found the root in inorder
            }
        }
        
        idx++; // Move to the next element in preorder
        TreeNode* root = new TreeNode(currVal); // Create the root node
        root->left = solve(preorder, inorder, start, j - 1, idx); // Build left subtree
        root->right = solve(preorder, inorder, j + 1, end, idx); // Build right subtree
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0; // Start with the first element in preorder
        int n = preorder.size();
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};
//DRY RUN
preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

Initial Setup:
preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]
idx = 0
First Call to solve:
start = 0, end = 4
currVal = preorder[idx] = 3
In inorder, find 3 between indices 0 and 4. It is found at index 1.
Create a TreeNode with value 3.
Increment idx to 1.
Now, recursively build the left and right subtrees:

Left Subtree:
Call solve(preorder, inorder, start = 0, end = 0, idx = 1).
currVal = preorder[idx] = 9
In inorder, find 9 between indices 0 and 0. It is found at index 0.
Create a TreeNode with value 9.
Increment idx to 2.
For the left and right subtrees of node 9:

Left Subtree of Node 9:
Call solve(preorder, inorder, start = 0, end = -1, idx = 2).
Since start > end, return NULL.
Right Subtree of Node 9:
Call solve(preorder, inorder, start = 1, end = 0, idx = 2).
Since start > end, return NULL.
Return the node 9 (with no children) to the previous call.

Right Subtree:
Call solve(preorder, inorder, start = 2, end = 4, idx = 2).
currVal = preorder[idx] = 20
In inorder, find 20 between indices 2 and 4. It is found at index 3.
Create a TreeNode with value 20.
Increment idx to 3.
For the left and right subtrees of node 20:

Left Subtree of Node 20:
Call solve(preorder, inorder, start = 2, end = 2, idx = 3).
currVal = preorder[idx] = 15
In inorder, find 15 between indices 2 and 2. It is found at index 2.
Create a TreeNode with value 15.
Increment idx to 4.
For the left and right subtrees of node 15:

Left Subtree of Node 15:
Call solve(preorder, inorder, start = 2, end = 1, idx = 4).
Since start > end, return NULL.
Right Subtree of Node 15:
Call solve(preorder, inorder, start = 3, end = 2, idx = 4).
Since start > end, return NULL.
Return the node 15 (with no children) to the previous call.

Right Subtree of Node 20:
Call solve(preorder, inorder, start = 4, end = 4, idx = 4).
currVal = preorder[idx] = 7
In inorder, find 7 between indices 4 and 4. It is found at index 4.
Create a TreeNode with value 7.
Increment idx to 5.
For the left and right subtrees of node 7:

Left Subtree of Node 7:
Call solve(preorder, inorder, start = 4, end = 3, idx = 5).
Since start > end, return NULL.
Right Subtree of Node 7:
Call solve(preorder, inorder, start = 5, end = 4, idx = 5).
Since start > end, return NULL.
Return the node 7 (with no children) to the previous call.

Final Tree Structure:
The node 3 becomes the root.
Its left child is 9 (no children).
Its right child is 20, whose left child is 15 (no children), and whose right child is 7 (no children).
The final binary tree looks like this:


    3
   / \
  9   20
     /  \
   15    7