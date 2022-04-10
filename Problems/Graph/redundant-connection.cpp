class UnionFind{
private:
    int numOfNodes;
    vector<int> sizeOfCluster;
    vector<int> parentOfCluster;
public:
    UnionFind(int n){
        numOfNodes = n;
        sizeOfCluster.resize(numOfNodes,1);
        parentOfCluster.resize(numOfNodes);
        for(int i=0;i<numOfNodes;++i){
            parentOfCluster[i] = i;
        }
    }
    
    int Find(int node){
        if(parentOfCluster[node]!=node){
            parentOfCluster[node] = Find(parentOfCluster[node]);
        }
        return parentOfCluster[node];
    }
    
    bool Union(int node1, int node2){
        int parent1 = Find(node1);
        int parent2 = Find(node2);
        if(sizeOfCluster[parent1]>sizeOfCluster[parent2]){
            parentOfCluster[parent2] = parent1;
            sizeOfCluster[parent1] += sizeOfCluster[parent1];
        }
        else if(sizeOfCluster[parent1]<=sizeOfCluster[parent2]){
            parentOfCluster[parent1] = parent2;
            sizeOfCluster[parent2] += sizeOfCluster[parent1];
        }
        return parent1 == parent2;
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind* uf = new UnionFind(edges.size());
        vector<int> retval;
        for(auto edge:edges){
            if(uf->Union(edge[0]-1, edge[1]-1)){
                retval = edge;
                break;
            }
        }
        return retval;
    }
};
