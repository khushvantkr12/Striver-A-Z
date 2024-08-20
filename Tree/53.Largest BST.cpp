//https://www.geeksforgeeks.org/problems/largest-bst/1

//TC-O(N)
//SC-O(1)
class Info {
    public:
    int maxi;
    int mini;
    int size;
};

class Solution {
    public:
    Info solve(Node *root, int &maxSize) {
        // Base case: If root is NULL, return a valid BST with size 0
        if (root == NULL) {
            
       return {INT_MIN,INT_MAX,0};
        }
        
        //POST ORDER TRAVERSAL
        Info left = solve(root->left, maxSize);
        Info right = solve(root->right, maxSize);
        //Buisness Logic:-
        // Initialize current node's info
        Info currNode;
        currNode.mini = INT_MIN;
        currNode.maxi = INT_MAX;
        currNode.size = 0;
        
        //IT IS BST
        if (root->data > left.maxi && root->data < right.mini) {
            currNode.mini = min(root->data, left.mini);
            currNode.maxi = max(root->data, right.maxi);
            currNode.size = left.size + right.size + 1;

            // Update maxSize if current subtree is a valid BST
            maxSize = max(maxSize, currNode.size);
        } else {
            currNode.size = max(left.size, right.size);
        }

        return currNode;
    }

    int largestBst(Node *root) {
        int maxSize = 0;
        Info temp = solve(root, maxSize);
        return maxSize;
    }
};
