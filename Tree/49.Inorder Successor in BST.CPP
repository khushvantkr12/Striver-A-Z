//TC-O(H)..HEIGHT OF THE TREE
//SC-O(1)
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* succ=NULL;
        while(root!=NULL){
            if(root->data<=x->data){
                root=root->right;
            }else{
                succ=root;
                root=root->left;
            }
        }
        return succ;
    }
};