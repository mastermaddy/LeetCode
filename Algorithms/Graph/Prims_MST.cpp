#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
private:
  int numOfVertices;
  list<pair<int, int>> *adjList;
public:
  Graph(int v){
    numOfVertices = v;
    adjList = new list<pair<int,int>> [numOfVertices];
  }
  
  void addEdge(int u, int v, int weight=0){
    adjList[u].push_back({v,weight});
  }
  
  int getNumOfVertices(){
    return numOfVertices;
  }
  
  list<pair<int,int>> getNeighbors(int vertex){
      return adjList[vertex];
  }
  
  void printMinSpanningTree(vector<int> &parent, numOfVertices){
    for(int i=0;i<numOfVertices;++i){
      cout<<"i: "<<i<<" "<<"parent: "<<parent[i]<<endl;
    }
  }
  
  void PrimsMST(int source = 0){
    int numOfVertices = getNumOfVertices();
    vector<int> parent(numOfVertices, -1);
    vector<int> minCost(numOfVertices, INT_MAX);
    vector<bool> isInMST(numOfVertices, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minPQ;
    minCost[source] = 0;
    minPQ.push({minCost[source],source});
    while(!minPQ.empty()){
      pair<int,int> currentVertex = minPQ.top();
      minPQ.pop();
      if(isInMST(currentVertex.second)){
        continue;
      }
      isInMST[cuurentVertex.second] = true;
      for(auto neighbor: getNeighbors(currentVertex.second)){
        if(!isInMST[neighbor.first] && minCost[neighbor.first]>neighbor.second){
          minCost[neighbor.first] = neighbor.second;
          minPQ.push(neighbor);
          parent[neighbor.first] = currentVertex.second;
        }
      }
    }
    printMinSpanningTree(parent, numOfVertices);
  }
};
