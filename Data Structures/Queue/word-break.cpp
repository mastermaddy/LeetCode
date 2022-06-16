class Solution {
public:
    bool wordBreak(string s, vector<string>& dict){
        queue<int> BFS;
        unordered_set<int> visited;
        BFS.push(0);
        while(BFS.size() > 0){
            int start = BFS.front();
            BFS.pop();
            if(visited.find(start) == visited.end()){
                visited.insert(start);
                for(int j=start; j<s.size(); j++){
                    string word = s.substr(start, j-start+1);
                    if(find(dict.begin(), dict.end(), word) != dict.end()){
                        BFS.push(j+1);
                        if(j+1 == s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
