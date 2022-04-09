class Solution {
public:
    int find(int currentVertex, vector<int> &parent){
        if(parent[currentVertex]!=currentVertex){
            parent[currentVertex] = find(parent[currentVertex], parent);
        }
        return parent[currentVertex];
    }
    
    void Union(int firstNode, int secondNode, vector<int> &parent, vector<int> &rank){
        if(rank[firstNode]>rank[secondNode]){
            parent[secondNode] = firstNode; 
        }
        else if(rank[firstNode]<rank[secondNode]){
            parent[firstNode] = secondNode;
        }
        else{
            parent[firstNode] = secondNode;
            rank[secondNode]+=rank[firstNode];
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end){
        vector<int> parent(n), rank(n);
        for(int i=0;i<n;++i){
            rank[i] = 0;
            parent[i] = i;
        }
        for(auto edge:edges){
            int firstParent = find(edge[0], parent);
            int secondParent = find(edge[1], parent);
            Union(firstParent, secondParent, parent, rank);
        }
        return find(start, parent) == find(end, parent);
    }
    
};
