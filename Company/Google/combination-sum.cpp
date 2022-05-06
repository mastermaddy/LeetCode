class Solution {
private:
    void combinationSum(vector<int> &candidates, int &candidateSize, int target, vector<vector<int>> &allCombinations, vector<int> currentCombination, int currentIndex){
        // base case
        if(target == 0){
            allCombinations.push_back(currentCombination);
            return;
        }
        if(target<0 || currentIndex>=candidateSize){
            return;
        }
        currentCombination.push_back(candidates[currentIndex]);
        combinationSum(candidates,candidateSize, target-candidates[currentIndex], allCombinations, currentCombination, currentIndex);
        currentCombination.pop_back();
        combinationSum(candidates,candidateSize, target, allCombinations, currentCombination, currentIndex+1);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombinations;
        vector<int> currentCombination;
        int currentIndex = 0;
        int candidateSize = candidates.size();
        combinationSum(candidates, candidateSize, target, allCombinations, currentCombination, currentIndex);
        return allCombinations;
    }
};
