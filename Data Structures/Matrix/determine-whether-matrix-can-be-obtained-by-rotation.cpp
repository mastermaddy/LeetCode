class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> invalidRotations(4, true);
        int rows = mat.size(), cols = mat[0].size();
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(mat[i][j]!=target[i][j]) invalidRotations[0] = false;
                if(mat[i][j]!=target[cols-j-1][i]) invalidRotations[1] = false;
                if(mat[i][j]!=target[rows-i-1][cols-j-1]) invalidRotations[2] = false;
                if(mat[i][j]!=target[j][cols-i-1]) invalidRotations[3] = false;
            }
        }
        return count(invalidRotations.begin(), invalidRotations.end(), true);
    }
};
