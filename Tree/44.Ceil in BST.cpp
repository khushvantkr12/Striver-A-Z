//https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

// Function to return the ceil of given number in BST.
 int solve(Node* root, int input) {
    // Base case
    if (root == NULL) {
        return -1; // Return -1 or some other appropriate value when no ceiling is found
    }

   
    if (root->data == input) {
        return root->data;
    }

   
    if (input < root->data) {
       int left_ceil=solve(root->left,input);
       if(left_ceil>=input && left_ceil!=-1){
          return solve(root->left,input);
       }else{
           return root->data;
       }
    }else{
     solve(root->right, input);
    }
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1; // No nodes in tree
    return solve(root, input);
}
