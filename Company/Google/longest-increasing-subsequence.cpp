class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for(auto num:nums){
            auto itr = lower_bound(LIS.begin(), LIS.end(), num);
            if(itr==LIS.end()){
                LIS.push_back(num);
            }
            else{
                *itr = num;
            }
        }
        return LIS.size();
    }
};
