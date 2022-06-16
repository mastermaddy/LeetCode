class Solution {
private:
    vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        vector<int> spiralOrderOutput;
        int currentDirection = 0, row = 0, col = -1, m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return spiralOrderOutput;
        int range[] = {n, m-1};
        while(range[currentDirection%2]){
            for(int element = 0; element < range[currentDirection%2];++element){
                row += directions[currentDirection].first;
                col += directions[currentDirection].second;
                spiralOrderOutput.push_back(matrix[row][col]);
            }
            range[currentDirection%2]--;
            currentDirection=(currentDirection+1)%4;   
        }
        return spiralOrderOutput;
    }
};
