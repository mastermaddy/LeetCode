class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Size = word1.size(), word2Size = word2.size();
        vector<vector<int>> dp(word1Size+1, vector<int>(word2Size+1, 0));
        for(int i=1;i<=word1Size;++i){
            dp[i][0] = i;
        }
        for(int i=1;i<=word2Size;++i){
            dp[0][i] = i;
        }
        for(int i=1;i<=word1Size;++i){
            for(int j=1;j<=word2Size;++j){
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[word1Size][word2Size];
    }
};
