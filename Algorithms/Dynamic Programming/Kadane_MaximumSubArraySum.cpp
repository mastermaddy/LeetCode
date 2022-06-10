class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevMaxSubArraySum = 0, maxSubArraySum = nums[0];
        for(auto num:nums){
            prevMaxSubArraySum = max(prevMaxSubArraySum+num, num); 
            maxSubArraySum = max(maxSubArraySum, prevMaxSubArraySum);
        }
        return maxSubArraySum;
    }
};
