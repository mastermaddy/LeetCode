class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> targetSumIndices;
        for(int i=0;i<nums.size();++i){
            auto itr = hashMap.find(target-nums[i]);
            if(itr!=hashMap.end()){
                targetSumIndices.push_back(i);
                targetSumIndices.push_back(itr->second);
                break;
            }
            else{
                hashMap[nums[i]] = i;
            }
        }
        return targetSumIndices;
    }
};
