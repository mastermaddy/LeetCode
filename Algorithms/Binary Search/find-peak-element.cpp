class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int numSize = nums.size();
        if(numSize>1){
            if(nums[0]>nums[1]){
                return 0;
            }
            if(nums[numSize-1]>nums[numSize-2]){
                return numSize-1;
            }
            int left = 1, right = numSize-2;
            while(left<=right){
                int mid = (left + right)/2;
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }
                if(nums[mid]<nums[mid-1]){
                    right = mid - 1;
                }
                else if(nums[mid]<nums[mid+1]){
                    left = mid + 1;
                }
            }
        }
        return numSize==1?0:-1;
    }
};
