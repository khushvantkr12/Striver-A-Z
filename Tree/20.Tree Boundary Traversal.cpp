//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
public:
    void Leftboundarynodes(Node *root, vector<int>&temp){
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        temp.push_back(root->data);
        if (root->left!=NULL) {
            Leftboundarynodes(root->left, temp);
        } else {
            Leftboundarynodes(root->right, temp);
        }
    }

    void Leafnodes(Node *root, vector<int>&temp){
        //INORDER TRAVERSAL
        if (root == NULL) {
            return;
        }
        Leafnodes(root->left, temp);
        if (root->left == NULL && root->right == NULL) {
            temp.push_back(root->data);
        }
        Leafnodes(root->right, temp);
    }

    void Reverserightboundarynodes(Node *root, vector<int>&temp){
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if (root->right!=NULL) {
            Reverserightboundarynodes(root->right, temp);
        } else {
            Reverserightboundarynodes(root->left, temp);
        }
        temp.push_back(root->data);  // add after recursion to reverse the order
    }

    vector<int> boundary(Node *root)
    {
        vector<int> temp;
       
          if((root->left!=NULL&& root->right!=NULL)|| (root->left!=NULL&& root->right==NULL)|| (root->left==NULL&& root->right!=NULL)){
              temp.push_back(root->data);
          }
        // Add left boundary nodes excluding the root and leaf nodes
        if (root->left!=NULL) {
            Leftboundarynodes(root->left, temp);
        }
       //add leaf
        Leafnodes(root, temp);

        // Add right boundary nodes excluding the root and leaf nodes, in reverse order
        if (root->right!=NULL) {
            Reverserightboundarynodes(root->right, temp);
        }

        return temp;
    }
};