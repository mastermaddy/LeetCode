class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto c:s){
            mp[c]++;
        }
        for(auto c:t){
            mp[c]--;
        }
        for(auto i:mp){
            if(i.second!=0) return false;
        }
        return true;
    }
};
