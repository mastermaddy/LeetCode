class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        unordered_map<int, vector<int>> graph;
        int maxNetworkRank = 0;
        for(auto road:roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j){
                    int currNetworkRank = degree[i] + degree[j];
                    if(find(graph[i].begin(),graph[i].end(),j)!=graph[i].end()){
                        currNetworkRank--;
                    }
                    maxNetworkRank = max(maxNetworkRank,currNetworkRank);
                }
            }
        }
        return maxNetworkRank;
    }
};
