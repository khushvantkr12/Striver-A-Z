//booyer moore vooting algorithm-->same element mile to count++ nahi mile to count-- if count becomes 0 then update the current element
//TC-O(n)
//SC-O(1)

class Solution {
public:
    // Booyer moore vooting algo
    // n/k se bada k-1 element(in best case) hi ho skta hai
    // n/3 means only 2 elements exist
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj1 = NULL;
        int count1 = 0;

        int maj2 = NULL;
        int count2 = 0;
        int freq = floor(n / 3);

        for (int i = 0; i < n; i++) {
            if (nums[i] == maj1)
                count1++;
            else if (nums[i] == maj2)
                count2++;
            else if (count1 == 0) {
                maj1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> result; // because atmost two elements can occur more than ⌊
                            // n/3 ⌋ in an array of length n
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == maj1)
                count1++;
            else if (num == maj2)
                count2++;
        }
        if (count1 > floor(n / 3))
            result.push_back(maj1);
        if (count2 > floor(n / 3))
            result.push_back(maj2);
        return result;
    }
};

//2ND APPROACH
//TC-O(n)
//SC-O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp; 
        vector<int>ans;
        int x=nums.size()/3;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
     for(auto it:mp){
         if(it.second>x){ //count of nums...
             ans.push_back(it.first);
         }
     }
     return ans;
    }
};
