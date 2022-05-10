class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());
        int longestConsecutiveSequence = 0;
        for(auto num:nums){
            int prev = num-1, next = num + 1;
            while(uniqueNumbers.find(prev) != uniqueNumbers.end()){
                uniqueNumbers.erase(prev--);
            }
            while(uniqueNumbers.find(next) != uniqueNumbers.end()){
                uniqueNumbers.erase(next++);
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, next - prev - 1);
        }
        return longestConsecutiveSequence;
    }
};
