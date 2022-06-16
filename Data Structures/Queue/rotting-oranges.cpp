class Solution {
private:
    vector<pair<int,int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols=grid[0].size();
        queue<pair<int,int>> q;
        int minutes = 0, rottenOranges=0, totalOranges=0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                    rottenOranges++;
                    totalOranges++;
                }
                else if(grid[i][j]==1){
                    totalOranges++;
                }
            }
        }
        while(!q.empty()){
            int qSize = q.size();
            minutes++;
            for(int i=0;i<qSize;++i){
                pair<int,int> currRottenOrangeLocation = q.front();
                q.pop();
                for(auto dir:directions){
                    if(currRottenOrangeLocation.first+dir.first>=0 && currRottenOrangeLocation.first+dir.first<rows){
                        if(currRottenOrangeLocation.second+dir.second>=0 && currRottenOrangeLocation.second+dir.second<cols){
                            if(grid[currRottenOrangeLocation.first+dir.first][currRottenOrangeLocation.second+dir.second]==1){
                                grid[currRottenOrangeLocation.first+dir.first][currRottenOrangeLocation.second+dir.second]=2;
                                q.push({currRottenOrangeLocation.first+dir.first, currRottenOrangeLocation.second+dir.second});
                                rottenOranges++;
                            }
                        }
                    }
                }
            }
        }
        return totalOranges==0?0:(rottenOranges==totalOranges?minutes-1:-1);
    }
};
