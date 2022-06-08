class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> profit(n+1,0);
        profit[1] = nums[0];
        for(int i=1;i<n;++i){
            profit[i+1] = max(nums[i]+profit[i-1], profit[i]); 
        }
        return profit[n];
    }
};
