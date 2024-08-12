//https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst
class Solution{
public:
    int solve(Node* root,int x){
        //base
        if(root==NULL){
            return -1;
        }
        if(root->data==x){
            return root->data;
        }
        
        if(root->data>x && root->right==NULL && root->left==NULL){
            return -1;
        }
        if(root->left==NULL && x<root->data){
            return -1;
        }
        if(root->data<x){
           int right_floor=solve(root->right,x);
            
            if(right_floor<=x && right_floor!=-1){
               return solve(root->right,x);
            }else{
                return root->data;
            }
        }
        
           solve(root->left,x);
        
          
    }
    int floor(Node* root, int x) {
        // Code here
        
        return solve(root,x);
    }
};