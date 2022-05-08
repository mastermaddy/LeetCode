class Solution{
// 1324 -> 1342 -> 1423 -> 1432 -> 2134 -> 2143 
public:
	void nextPermutation(vector<int> &nums){
		int sz = nums.size(), firstSmallFromRightIdx, largerThanFirstSmallIdx;
        for(firstSmallFromRightIdx=sz-2;firstSmallFromRightIdx>=0;--firstSmallFromRightIdx){
            if(nums[firstSmallFromRightIdx]<nums[firstSmallFromRightIdx+1]){
                break;
            }
        }
        if(firstSmallFromRightIdx<0){
            reverse(nums.begin(), nums.end());
        }
        else {
            for(largerThanFirstSmallIdx = sz-1;largerThanFirstSmallIdx>firstSmallFromRightIdx;--largerThanFirstSmallIdx){
                if(nums[largerThanFirstSmallIdx]>nums[firstSmallFromRightIdx]){
                    break;
                }
            }
            swap(nums[largerThanFirstSmallIdx],nums[firstSmallFromRightIdx]);
            reverse(nums.begin()+firstSmallFromRightIdx+1,nums.end());
        }
	}
};
