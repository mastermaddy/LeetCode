class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, startIndex=0, end =0,  counter =0, minLength = INT_MAX, sLen = s.length();
        unordered_map<char,int> mp;
        for(auto c:t){
            mp[c]++;
            counter++;
        }
        while(end<sLen){
            if(mp[s[end]]>0){
                counter--;
            }
            mp[s[end]]--;
            end++;
            while(counter==0){
                if((end-start)<minLength){
                    minLength = end - start;
                    startIndex = start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0){
                    counter++;
                }
                start++;
            }
        }
        if(minLength!=INT_MAX){
            return s.substr(startIndex, minLength);
        }
        return "";
    }
};
