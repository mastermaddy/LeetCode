class Solution {
public:
    int longestConsecutive(vector<int> & nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        int longestConsecutiveSequenceLength = 0;
        for(auto num:nums){
            int prev = num-1, next = num+1;
            while(uniqueNums.find(prev)!=uniqueNums.end()){
                uniqueNums.erase(prev--);
            }
            while(uniqueNums.find(next)!=uniqueNums.end()){
                uniqueNums.erase(next++);
            }
            longestConsecutiveSequenceLength = max(longestConsecutiveSequenceLength, next - prev - 1);
        }
        return longestConsecutiveSequenceLength;
    }
};
