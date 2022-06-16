class Solution {
vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> generatedMatrix(n,vector<int>(n));
        int rows = n-1, cols = n, row = 0, col = -1, currentDirection = 0, currentNumber = 1;
        vector<int> range = {cols, rows};
        while(range[currentDirection%2]){
            for(int element=0;element<range[currentDirection%2];++element){
                row+=directions[currentDirection].first;
                col+=directions[currentDirection].second;
                generatedMatrix[row][col] = currentNumber;
                currentNumber++;
            }
            range[currentDirection%2]--;
            currentDirection = (currentDirection+1)%4;
        }
        return generatedMatrix;
    }
};
