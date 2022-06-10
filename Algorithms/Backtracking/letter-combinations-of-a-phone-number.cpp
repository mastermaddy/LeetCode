class Solution {
private:
    unordered_map<char, string> digitToLetter = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
public:
    
    void letterCombinations(string digits,vector<string> &allLetterCombinations, string currentCombination, int currentIndex){
        if(currentIndex==digits.size()){
            if(currentCombination!="")
            allLetterCombinations.push_back(currentCombination);
            return;
        }
        for(char c: digitToLetter[digits[currentIndex]]){
            letterCombinations(digits,allLetterCombinations,currentCombination+c, currentIndex+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> allLetterCombinations;
        letterCombinations(digits,allLetterCombinations,"",0);
        return allLetterCombinations;
    }
};
