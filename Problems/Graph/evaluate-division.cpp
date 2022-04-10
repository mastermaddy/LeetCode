class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> result(queries.size());    
        for (int i = 0; i < queries.size(); i++) {
            set<string> visited;
            result[i] = getPathWeight(queries[i][0], queries[i][1],visited, graph);
        }    
        return result;
    }
    
    double getPathWeight(string start, string end, set<string> &visited, unordered_map<string, unordered_map<string, double>> &graph) {
        if (graph.find(start)==graph.end()) 
            return -1.0;
        
        if (graph[start].find(end) != graph[start].end())
            return graph[start][end];
        
        visited.insert(start);
        for(auto neighbour : graph[start]) {
            if (visited.find(neighbour.first)==visited.end()) {
                double productWeight = getPathWeight(neighbour.first, end, visited, graph);
                if (productWeight != -1.0)
                    return neighbour.second * productWeight;
            }
        }
        return -1.0;
    }
    
    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;
        string u, v;
        
        for (int i = 0; i < equations.size(); i++) {
            u = equations[i][0];
            v = equations[i][1];
            graph[u][v] = values[i];
            graph[v][u] = 1/values[i];
        }
        return graph;
    }
};
