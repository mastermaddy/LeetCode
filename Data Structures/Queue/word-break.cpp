class Solution {
public:
    bool wordBreak(string s, vector<string>&dict) {
        int strLength = s.length();
        unordered_map<string, int> dictionary;
        unordered_set<int> visited;
        queue<int> q;
        for(auto word:dict){
            dictionary[word]++;
        }
        q.push(0);
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(visited.find(start)==visited.end()){
                visited.insert(start);
                for(int i=start;i<strLength;++i){
                    if(dictionary.find(s.substr(start, i-start+1))!=dictionary.end()){
                        q.push(i+1);
                        if(i+1==strLength){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
