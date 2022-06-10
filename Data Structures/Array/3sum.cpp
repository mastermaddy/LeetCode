class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, int target){
        vector<vector<int>> twoSumResult;
        while (left<right) {
            int sum = nums[left]+nums[right];
            if (sum>target) right--;
            else if (sum<target) left++;
            else {
                twoSumResult.push_back(vector<int> {nums[left], nums[right]});
                while (left<right && nums[left]==nums[left+1]) left++;
                while (left<right && nums[right]==nums[right-1]) right--;
                left++; right--;
            }
        }
        return twoSumResult;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSumResult;
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        for(int i=0;i<numsSize;++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            vector<vector<int>> twoSumResult = twoSum(nums,i+1,numsSize-1,-1*nums[i]);
            if (twoSumResult.size()) {
                for (auto twoSumPair : twoSumResult) {
                    threeSumResult.push_back({nums[i]});
                    threeSumResult.back().insert(threeSumResult.back().end(), twoSumPair.begin(), twoSumPair.end());
                }
            }
        }
        return threeSumResult;
    }
};


