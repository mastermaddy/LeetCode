class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<int> uniqueChars;
        int longestSubstringLength = 0;
        for(int left=0, right=0;right<s.length();++right){
            if(uniqueChars.find(s[right])!=uniqueChars.end()){
                while(left<right && s[left]!=s[right]){
                    uniqueChars.erase(s[left++]);
                }
                ++left;
            }
            else{
                uniqueChars.insert(s[right]);
            }
            longestSubstringLength = max(longestSubstringLength, right - left + 1);
        }
        return longestSubstringLength;
    }
};
