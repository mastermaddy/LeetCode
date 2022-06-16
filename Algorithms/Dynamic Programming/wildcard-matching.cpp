class Solution {
public:
    bool isMatch(string str, string pat) {
        int strSize = str.size(), patSize = pat.size();
        vector<vector<bool>> dp(strSize+1, vector<bool>(patSize+1, false));
        dp[0][0] = true;
        for(int j=0;j<patSize && pat[j]=='*'; ++j){
            dp[0][j+1] = true;
        }
        for(int i=1;i<=strSize;++i){
            for(int j=1;j<=patSize;++j){
                if(pat[j-1]=='*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else{
                    dp[i][j] = (str[i-1]==pat[j-1] || pat[j-1]=='?') && dp[i-1][j-1];
                }
            }
        }
        return dp[strSize][patSize];
    }
};
