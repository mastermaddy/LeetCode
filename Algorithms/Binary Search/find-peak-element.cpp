class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int numSize = nums.size();
        int left = 0, right = numSize-1;
        while(left<right){
            int mid = (left + right)/2;
            if(nums[mid]>nums[mid+1]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
