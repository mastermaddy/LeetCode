class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> smallestSetOfVertices;
        vector<int> inDegrees(n,0);
        for(auto edge:edges){
            inDegrees[edge[1]]++;
        }
        for(int i=0;i<n;++i){
            if(inDegrees[i]==0){
                smallestSetOfVertices.push_back(i);
            }
        }
        return smallestSetOfVertices;
    }
};
