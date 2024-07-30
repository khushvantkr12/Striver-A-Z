//https://www.geeksforgeeks.org/problems/binary-tree-representation/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-tree-representation

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*>q;
        q.push(root0);
        int i=1;
        while(!q.empty()){
           node* x=q.front();
            q.pop();
            if( i<vec.size() ){
                x->left =newNode(vec[i]);
                q.push(x->left);
                i++;
            }
            if( i< vec.size() ){
                x->right = newNode(vec[i]);
                q.push(x->right);
                i++;
            }
        }
    }

};