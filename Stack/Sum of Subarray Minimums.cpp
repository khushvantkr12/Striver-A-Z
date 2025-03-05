class Solution {
public:
   int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
    //find how many NSE from left to right
    //in stack push index instead of arr[i]
    //find how many NSE from right to left
    //then multiply this
        
        int n = arr.size();
        stack<int> st1, st2;
        vector<int> nextsmallerRtoL(n, 0);
        vector<int> nextsmallerLtoR(n, 0);

        // Compute Next Smaller Element distances (Right to Left)
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] <= arr[st1.top()]) {
                st1.pop();
            }
            if (st1.empty()) {
                nextsmallerRtoL[i] = n - i;
            } else {
                nextsmallerRtoL[i] = st1.top() - i;
            }
            st1.push(i);
        }

        // Compute Next Smaller Element distances (Left to Right)
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[i] < arr[st2.top()]) {
                st2.pop();
            }
            if (st2.empty()) {
                nextsmallerLtoR[i] = i + 1;
            } else {
                nextsmallerLtoR[i] = i - st2.top();
            }
            st2.push(i);
        }

        // Compute the result
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count = (count + (long long)arr[i] * nextsmallerRtoL[i] * nextsmallerLtoR[i]) % MOD;
        }
        return count;
    
    }
};