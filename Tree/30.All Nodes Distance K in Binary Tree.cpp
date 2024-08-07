//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    
    void solve(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        // Store parent for each node
        if (root->left) {
            mp[root->left] = root;
            solve(root->left);
        }
        if (root->right) {
            mp[root->right] = root;
            solve(root->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Create a parent map
        solve(root);
        
       
        unordered_map<TreeNode*, bool> visited;
        
        // Step 3: Perform BFS from the target node
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int currentLevel = 0;
        vector<int> ans;
        
        while (!q.empty()) {
            int sz = q.size();
            
            // If the current level is k, collect all nodes at this level
            if (currentLevel == k) {
                while (sz--) {
                    TreeNode* node = q.front();
                    q.pop();
                    ans.push_back(node->val);
                }
                break; 
            }
            
            // Process all nodes at the current level
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                
                // Traverse left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                // Traverse right child
                if (node->right && !visited[node->right] ) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // Traverse parent
                if (mp.find(node) != mp.end() && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
            currentLevel++;
        }
        
        return ans;
    }
};
