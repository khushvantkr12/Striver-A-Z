Algorithm
Initialize Two Stacks

asc → Maintains a monotonic decreasing stack (stores elements in decreasing order).
desc → Temporary stack used for rearranging elements.
Iterate Backwards from n-1 to 0

This ensures that we process elements from right to left.
We use a stack-based approach to track greater elements to the right.
Process Each Element (arr[i])

Remove Smaller Elements:
Pop all elements from asc that are less than or equal to arr[i] and push them into desc.
This ensures only greater elements remain in asc.
Store Count of Greater Elements:
The remaining elements in asc are greater than arr[i], so asc.size() gives the NGE count for index i.
Restore asc Stack:
Move all elements from desc back to asc to maintain order.
Answer Queries Efficiently

The result array v[] is precomputed, so for each query, we simply return v[indices[i]] in O(1) time.

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        //int n=arr.size();
        vector<int>ans(n,0);
        stack<int>asc;
        stack<int>desc;
        
        for(int i=n-1; i>=0; i--){
            //apply NGE
            //in asc stack we will store element in ascending order so that we easily get size of stack
            while(!asc.empty() && arr[i]>=asc.top()){
                desc.push(asc.top());
                asc.pop();
            }
            desc.push(arr[i]);
            ans[i]=asc.size();
            while(!desc.empty()){
                asc.push(desc.top());
                desc.pop();
            }
        }
        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }cout<<endl;
        for(int i=0; i<queries; i++){
            indices[i]=ans[indices[i]];
        }
        return indices;
    }

};