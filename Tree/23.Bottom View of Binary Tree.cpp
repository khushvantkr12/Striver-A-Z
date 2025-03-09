//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

////idea is keep pushing level and val in queue and if it process right then add +1 else -1..
//then push it into stack..then take a map and comapre if level is not repeated previously 
//in stack if it then ignore otherwise push into map..then finally push into vector from map..
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<int,Node*>>q;
        q.push({0,root});
        stack<pair<int,int>>st;
        vector<int>ans;
        map<int,int>mp;
        
        if(root==NULL){
            return ans;
        }
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                Node* x=q.front().second;
                int y=q.front().first;
                q.pop();
                
                st.push({y,x->data});
                
                if(x->left){
                    q.push({y-1,x->left});
                }
                 if(x->right){
                    q.push({y+1,x->right});
                }
            }
        }
    //     while (!st.empty()) {
    //     std::cout << st.top() << " ";
    //     st.pop();
    // }
 
        while(!st.empty()){
            int level=st.top().first;
            int node=st.top().second;
           // st.pop();
            
            if(mp.find(level)==mp.end()){
                mp.insert({level,node});
            }
            st.pop();
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};