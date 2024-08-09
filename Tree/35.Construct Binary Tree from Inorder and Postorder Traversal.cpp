//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx){
        //base
        if(start>end){
            return NULL;
        }
        int root_node=postorder[idx];//root nikal liye
        int j=start;
        
       
        for(int i=start; i<=end; i++){
            if(inorder[i]==root_node){
                j=i;
                break;
            }
        }
        idx--;
        TreeNode* root=new TreeNode(root_node); 
        //why right before left?
        //Postorder traversal processes the right subtree before the left subtree because when you're constructing the tree backwards (from the end of the postorder array), the right subtree comes before the left subtree in the postorder list.
        root->right=solve(inorder,postorder,j+1,end,idx);
        root->left=solve(inorder,postorder,start,j-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        int idx=n-1;
        return solve(inorder,postorder,0,n-1,idx);

    }
};