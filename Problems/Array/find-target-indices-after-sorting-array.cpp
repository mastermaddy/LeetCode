class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, position = 0;
        vector<int> targetIndices;
        for(auto num:nums){
            count += (num==target);
            position += (num<target);
        }
        while(count--){
            targetIndices.push_back(position++);
        }
        return targetIndices;
    }
};
