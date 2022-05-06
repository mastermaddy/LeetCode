class Solution {
private:
    vector<string> numberToLetters = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};

    void getLetterCombinations(string digits, int digitSize, vector<string> &allLetterCombinations, string currentCombination = "", int currentIndex = 0){
        if(currentIndex == digitSize){
            if(currentCombination!=""){
                allLetterCombinations.push_back(currentCombination);
            }
            return;
        }
        for(char c:numberToLetters[digits[currentIndex] - '1']){
            getLetterCombinations(digits,digitSize,allLetterCombinations, currentCombination + c,currentIndex+1);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> allLetterCombinations;
        getLetterCombinations(digits, digits.size(), allLetterCombinations);
        return allLetterCombinations;
    }
};
