class Solution {
public:
    bool isMatch(string str, string pat) {
        int strSize = str.size(), patSize = pat.size();
        vector<vector<bool>> dp(strSize+1, vector<bool>(patSize+1, false));
        dp[0][0] = true;
        for(int j=1;j<=patSize;++j){
            dp[0][j] = j>1 && pat[j-1] == '*' && dp[0][j-2];
        }
        for(int i=1;i<=strSize;++i){
            for(int j=1;j<=patSize;++j){
                if(pat[j-1]!='*'){
                    dp[i][j] = (str[i-1]==pat[j-1] || pat[j-1]=='.') && dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-2] || (str[i-1]==pat[j-2] || pat[j-2]=='.') && dp[i-1][j];
                }
            }
        }
        return dp[strSize][patSize];
    }
};
