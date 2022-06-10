class Solution {
private:
    void generateParentheses(int numOfOpenBrackets, int numOfClosedBrackets, int &n, vector<string> &allParentheses, string currentParentheses){
        if(numOfClosedBrackets>numOfOpenBrackets || numOfOpenBrackets>n || numOfClosedBrackets>n){
            return;
        }
        else if(numOfClosedBrackets==numOfOpenBrackets && numOfOpenBrackets==n){
            allParentheses.push_back(currentParentheses);
            return;
        }
        else{
            generateParentheses(numOfOpenBrackets+1, numOfClosedBrackets, n, allParentheses, currentParentheses+'(');
            generateParentheses(numOfOpenBrackets, numOfClosedBrackets+1, n, allParentheses, currentParentheses+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int numOfOpenBrackets = 0, numOfClosedBrackets=0;
        string currentParentheses = "";
        vector<string> allParentheses;
        generateParentheses(numOfOpenBrackets, numOfClosedBrackets, n, allParentheses, currentParentheses);
        return allParentheses;
    }
};
