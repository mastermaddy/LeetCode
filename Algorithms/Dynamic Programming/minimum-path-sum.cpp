class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector< vector<int> > min_sum_path(m, vector<int>(n,0));
        min_sum_path[0][0] = grid[0][0];
        for(int i=1;i<m;++i){
            min_sum_path[i][0] = min_sum_path[i-1][0] + grid[i][0];
        }
        for(int i=1;i<n;++i){
            min_sum_path[0][i] = min_sum_path[0][i-1] + grid[0][i];
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                min_sum_path[i][j] = min(min_sum_path[i-1][j], min_sum_path[i][j-1]) + grid[i][j];
            }
        }
        return min_sum_path[m-1][n-1];
    }
};
