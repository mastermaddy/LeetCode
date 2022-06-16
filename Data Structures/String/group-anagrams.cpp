class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &inputStrings){
        unordered_map<string, vector<string>> dictionary;
        vector<vector<string>> groupedAnagrams;
        for(auto str:inputStrings){
            string currString = str;
            sort(currString.begin(), currString.end());
            dictionary[currString].push_back(str);
        }
        for(auto anagrams:dictionary){
            groupedAnagrams.push_back(anagrams.second);
        }
        return groupedAnagrams;   
    } 
};
