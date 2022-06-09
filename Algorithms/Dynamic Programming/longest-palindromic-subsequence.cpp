class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int strLength = s.length();
        vector<vector<int>> dp(strLength, vector<int>(strLength, 0));
        for(int i=strLength-1;i>=0;--i){
            dp[i][i] = 1;
            for(int j=i+1;j<strLength;++j){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][strLength-1];
    }
};
