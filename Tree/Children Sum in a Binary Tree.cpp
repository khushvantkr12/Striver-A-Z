//https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent

class Solution{
    public:
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
    
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        
        if(left+right==root->data){
            return root->data;
        }
      return -1000;
    }
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
       int ans= solve(root);
       if(ans==root->data){
           return 1;
       }
       return 0;
    }
};