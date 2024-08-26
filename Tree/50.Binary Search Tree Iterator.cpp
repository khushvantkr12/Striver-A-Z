//https://leetcode.com/problems/binary-search-tree-iterator/description/

class BSTIterator {
public:
    stack<TreeNode*> st;

   
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        TreeNode* y=topNode->right;
       while(y){
         st.push(y);
         y=y->left;
       }
       return topNode->val;
    }

   
    bool hasNext() {
        return !st.empty();
    }
};