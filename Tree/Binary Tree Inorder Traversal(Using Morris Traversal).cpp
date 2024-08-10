class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                
                TreeNode* temp = curr->left;  

                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                    // Make a temporary link to the current node
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    // Remove the temporary link
                    temp->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

//DRY RUN
In-order Traversal (expected result):
The expected in-order traversal of this tree is [1, 2, 3, 4, 5, 6, 7].

Morris Traversal Process:
Start at Root (4):

curr = 4
curr has a left child (2), so we need to find the rightmost node in the left subtree.
Find Rightmost Node in Left Subtree of 4 (Starting from 2):

temp = 2
Move right from 2 to 3, and 3 has no right child, so temp = 3.
Now, temp->right is NULL.
Create Temporary Link from 3 to 4:

temp->right = 4 (creates a temporary link)
Move curr to the left child: curr = 2
Process Node 2:

curr = 2
curr has a left child (1), so find the rightmost node in the left subtree.
Find Rightmost Node in Left Subtree of 2 (Starting from 1):

temp = 1
1 has no right child, so temp->right is NULL.
Create Temporary Link from 1 to 2:

temp->right = 2 (creates a temporary link)
Move curr to the left child: curr = 1
Process Node 1:

curr = 1
curr has no left child, so add 1 to the result: ans = [1]
Move curr to the right: curr = 2 (follows the temporary link from 1->right = 2)
Return to Node 2:

curr = 2 again, but now temp->right points back to curr (temporary link created earlier).
Remove the temporary link (temp->right = NULL).
Add 2 to the result: ans = [1, 2]
Move curr to the right child: curr = 3
Process Node 3:

curr = 3
curr has no left child, so add 3 to the result: ans = [1, 2, 3]
Move curr to the right: curr = 4 (follows the temporary link from 3->right = 4)
Return to Root Node 4:

curr = 4 again, but now temp->right points back to curr (temporary link created earlier).
Remove the temporary link (temp->right = NULL).
Add 4 to the result: ans = [1, 2, 3, 4]
Move curr to the right child: curr = 6
Process Node 6:

curr = 6
curr has a left child (5), so find the rightmost node in the left subtree.
Find Rightmost Node in Left Subtree of 6 (Starting from 5):

temp = 5
5 has no right child, so temp->right is NULL.
Create Temporary Link from 5 to 6:

temp->right = 6 (creates a temporary link)
Move curr to the left child: curr = 5
Process Node 5:

curr = 5
curr has no left child, so add 5 to the result: ans = [1, 2, 3, 4, 5]
Move curr to the right: curr = 6 (follows the temporary link from 5->right = 6)
Return to Node 6:

curr = 6 again, but now temp->right points back to curr (temporary link created earlier).
Remove the temporary link (temp->right = NULL).
Add 6 to the result: ans = [1, 2, 3, 4, 5, 6]
Move curr to the right child: curr = 7
Process Node 7:

curr = 7
curr has no left child, so add 7 to the result: ans = [1, 2, 3, 4, 5, 6, 7]
Move curr to the right: curr = NULL
Final Result:
The final in-order traversal stored in ans is [1, 2, 3, 4, 5, 6, 7].