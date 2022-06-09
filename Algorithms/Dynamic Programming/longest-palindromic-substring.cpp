class Solution {
public:
    string longestPalindrome(string s) {
        int strLength = s.length(), longestPalindromeSubstringLength = 1;
        string longestPalindromeSubstring = string(1, s[0]);
        vector<vector<bool>> dp(strLength,vector<bool>(strLength,false));
        for(int high=0;high<strLength;++high){
            dp[high][high] = true;
            for(int low=0;low<high;++low){
                if (s[low]!=s[high]) continue;
                if (low + 1 < high - 1 && !dp[low + 1][high - 1]) continue;
                dp[low][high] = true;
                if(longestPalindromeSubstringLength<high-low+1){
                    longestPalindromeSubstringLength = high - low + 1;
                    longestPalindromeSubstring = s.substr(low, longestPalindromeSubstringLength);
                }
            }
        }
        return longestPalindromeSubstring;
    }
};
