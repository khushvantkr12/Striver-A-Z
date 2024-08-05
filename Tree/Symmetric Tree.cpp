//https://leetcode.com/problems/symmetric-tree/description/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
       
        queue<TreeNode*> q;
        q.push(root);
         
        while (!q.empty()) {
            int sz = q.size();
           vector<int> ans;
            
           while(sz--){
                TreeNode* x = q.front();
                q.pop();
                    
                    //why this INT_MIN is push..because it checks symmetry at each steps..so if int_min is eqaul to some number then we return false;
                    if (x == NULL) {
                    ans.push_back(INT_MIN);
                    continue;
                } else {
                    ans.push_back(x->val);
                }
                
                q.push(x->left);
                q.push(x->right);
                
            }
            
            int i = 0, j = ans.size()-1 ;
            while (i < j) {
                
                if (ans[i] != ans[j]) {
                    return false;
                }
                i++;
                j--;
            }
            
        }
        
        return true;
    }
};
