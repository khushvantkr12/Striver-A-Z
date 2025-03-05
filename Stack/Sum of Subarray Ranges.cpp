class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
         //key step
        //for every index try find its maximum count from right side as well left side similarly for minimum case then multiply both
        //then take(max-min)*nums[i] and add
        if (nums.empty()) {
            return 0;
        }

        long long n = nums.size();
        vector<int> maximumFromLeftToRight(n, 1);
        vector<int> maximumFromRightToLeft(n, 1);
        vector<int> minimumFromRightToLeft(n, 1);
        vector<int> minimumFromLeftToRight(n, 1);

        stack<int> stackOne;
        stack<int> stackTwo;
        stack<int> stackThree;
        stack<int> stackFour;
        
        //maximum from right to left
        for (long long i = n - 1; i >= 0; i--) {
            while (!stackOne.empty() && nums[i] > nums[stackOne.top()]) {
                stackOne.pop();
            }
            if (stackOne.empty()) {
                maximumFromRightToLeft[i] = n - i;
            } else {
                maximumFromRightToLeft[i] = stackOne.top() - i;
            }
            stackOne.push(i);
        }
       
        //maximum from left to right
        for (long long i = 0; i < n; i++) {
            while (!stackTwo.empty() && nums[i] >= nums[stackTwo.top()]) {
                stackTwo.pop();
            }
            if (stackTwo.empty()) {
                maximumFromLeftToRight[i] = i + 1;
            } else {
                maximumFromLeftToRight[i] = i - stackTwo.top();
            }
            stackTwo.push(i);
        }
        //minimum from right to left
        for (long long i = n - 1; i >= 0; i--) {
            while (!stackThree.empty() && nums[i] < nums[stackThree.top()]) {
                stackThree.pop();
            }
            if (stackThree.empty()) {
                minimumFromRightToLeft[i] = n - i;
            } else {
                minimumFromRightToLeft[i] = stackThree.top() - i;
            }
            stackThree.push(i);
        }
       //minimum from left to right
        for (long long i = 0; i < n; i++) {
            while (!stackFour.empty() && nums[i] <= nums[stackFour.top()]) {
                stackFour.pop();
            }
            if (stackFour.empty()) {
                minimumFromLeftToRight[i] = i + 1;
            } else {
                minimumFromLeftToRight[i] = i - stackFour.top();
            }
            stackFour.push(i);
        }

        vector<long long> maximum(n, 1);
        vector<long long> minimum(n, 1);
        for (long long i = 0; i < n; i++) {
            maximum[i] = (long long)maximumFromLeftToRight[i] * maximumFromRightToLeft[i];
            minimum[i] = (long long)minimumFromLeftToRight[i] * minimumFromRightToLeft[i];
        }

        long long answer = 0;
        for (long long i = 0; i < n; i++) {
            answer += (maximum[i] - minimum[i]) * nums[i];
        }
        return answer;
    }
};