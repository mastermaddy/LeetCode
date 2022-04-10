class Solution {
    public:
    void dfs(int currentNode,int parent,vector<vector<int>> &adjList,vector<vector<int>> &outgoing,vector<bool> &visited,int &minEdgeReorder){
        visited[currentNode]=true;
        if(parent!=-1){
            if(find(outgoing[currentNode].begin(),outgoing[currentNode].end(),parent)==outgoing[currentNode].end())
                minEdgeReorder++;
        }
        for(auto i: adjList[currentNode]){
            if(!visited[i]){
                dfs(i,currentNode,adjList,outgoing,visited,minEdgeReorder);
            }
        }
     }
    int minReorder(int n, vector<vector<int>>& connections) {
            int minEdgeReorder=0, capital=0, parent=-1;
            vector<vector<int>> adjList(n);
            vector<vector<int>> outgoing(n);
            vector<bool> visited(n,false);       
            for(auto i: connections){
                adjList[i[0]].push_back(i[1]);
                adjList[i[1]].push_back(i[0]);
                outgoing[i[0]].push_back(i[1]);
            }
            dfs(capital,parent,adjList,outgoing,visited,minEdgeReorder);
            return minEdgeReorder;
     }
};
