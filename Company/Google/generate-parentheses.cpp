class Solution {
private:
    void generateParenthesis(int n, int numOfOpenParenthesis, int numOfCloseParenthesis, vector<string> &allCombinations, string currentCombination=""){
        if(numOfOpenParenthesis>n || numOfCloseParenthesis>numOfOpenParenthesis){
            return;
        }
        if(numOfOpenParenthesis==n && numOfCloseParenthesis==numOfOpenParenthesis){
            allCombinations.push_back(currentCombination);
        }
        generateParenthesis(n,numOfOpenParenthesis+1,numOfCloseParenthesis,allCombinations, currentCombination+"(");
        generateParenthesis(n,numOfOpenParenthesis,numOfCloseParenthesis+1,allCombinations, currentCombination+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allCombinations;
        generateParenthesis(n,0,0,allCombinations);
        return allCombinations;
    }
};
