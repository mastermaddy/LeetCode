class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n,0);
        unordered_map<int,vector<int>> adj;
        queue<int> leafNodes;
        vector<int> rootNodes;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        for(int i=0;i<n;++i){
            if(degrees[i]==1){
                leafNodes.push(i);
            }
        }
        while(!leafNodes.empty()){
            rootNodes.clear();
            int sz = leafNodes.size();
            for(int i=0;i<sz;++i){
                int leafNode = leafNodes.front();
                leafNodes.pop();
                rootNodes.push_back(leafNode);
                for(auto neighbor:adj[leafNode]){
                    degrees[neighbor]--;
                    if(degrees[neighbor]==1){
                        leafNodes.push(neighbor);
                    }
                }
            }
        }
        if(!rootNodes.size()) rootNodes.push_back(0);
        return rootNodes;
    }
};
