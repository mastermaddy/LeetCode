/*
  Problem: Find the maximum SubArray Sum:
  Solution: Current Element in the array is either part of a potential max subarray or not. If it is then see if the current subArray has maximum Sum. 
            If not, then drop that subarray and start subarray again from that element itself. 
*/

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
