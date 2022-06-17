class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums){
        vector<string> allSummaryRanges;
        int start=0, end = 0, sz = nums.size();
        for(int i=0;i<sz;++i){
            start = nums[i];
            while (i != (sz - 1) && nums[i] == nums[i + 1] - 1){
                i++;
            }
            int end = nums[i];
            if(start==end){
                allSummaryRanges.push_back(to_string(start));
            }
            else{
                allSummaryRanges.push_back(to_string(start) + "->" + to_string(end));
            }
        }
        return allSummaryRanges;
    }
};
