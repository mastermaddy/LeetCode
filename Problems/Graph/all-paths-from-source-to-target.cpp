class Solution {
public:
    void getPathFromSourceToTarget(int &source, int &target, vector<int> currentPath, vector<vector<int>> &allPathsFromSourceToTarget, vector<vector<int>> &graph){
        if(source==target){
            currentPath.push_back(target);
            allPathsFromSourceToTarget.push_back(currentPath);
            return;
        }
        currentPath.push_back(source);
        for(auto neighbor:graph[source]){ 
            getPathFromSourceToTarget(neighbor,target,currentPath,allPathsFromSourceToTarget, graph);
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        int source = 0, target = graph.size()-1;
        vector<vector<int>> allPathsFromSourceToTarget;
        vector<int> currentPath;
        for(auto neighbor:graph[source]){
            currentPath.push_back(source);
            getPathFromSourceToTarget(neighbor, target, currentPath, allPathsFromSourceToTarget, graph);
            currentPath.clear();
        }
        return allPathsFromSourceToTarget;
    }
};
