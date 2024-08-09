//https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree

class Solution {
  public:
    map<Node*, Node*> mp;  // To store the parent pointers
    
    void solve(Node* root) {
        if (root == NULL) {
            return;
        }
        
        if (root->left) {
            mp[root->left] = root;
            solve(root->left);
        }
        if (root->right) {
            mp[root->right] = root;
            solve(root->right);
        }
    }
    
    int minTime(Node* root, int target) {
        if (root == NULL) return 0;
        
        // First, build the parent map
        solve(root);
        
        // Find the target node and initialize the burning process
        queue<Node*> q;
        Node* targetNode = NULL;
        
        queue<Node*> q1;
        q1.push(root);
        
        while (!q1.empty()) {
            Node* y = q1.front();
            q1.pop();
            if (y->data == target) {
                targetNode = y;
                break;
            }
            if (y->left) q1.push(y->left);
            if (y->right) q1.push(y->right);
        }
        
       
        
        q.push(targetNode);
        
        map<Node*, bool> visited;
        visited[targetNode] = true;
        
        int count = 0;
        
        while (!q.empty()) {
            int sz = q.size();
           
            
            while (sz--) {
                Node* x = q.front();
                q.pop();
                
                if (x->left && !visited[x->left]) {
                    q.push(x->left);
                    visited[x->left] = true;
                   
                }
                if (x->right && !visited[x->right]) {
                    q.push(x->right);
                    visited[x->right] = true;
                   
                }
                if (mp.find(x) != mp.end() && !visited[mp[x]]) {
                    q.push(mp[x]);
                    visited[mp[x]] = true;
                    
                }
            }
            
           
            count++;
        }
        
        return count-1;
    }
};