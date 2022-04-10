class Solution {
public:
    int getNumOfNegativesInList(vector<int> numArray, int low, int high){
        while(low<=high){
            int mid = low + (high - low)/2;
            if(numArray[mid]>=0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return numArray.size() - high - 1;
    }
    
    int countNegatives(vector<vector<int>> &grid){
        int numOfRows = grid.size(), numOfCols = grid[0].size();
        int numOfNegatives = 0;
        for(auto row:grid){
            numOfNegatives += getNumOfNegativesInList(row, 0, numOfCols-1);
        }
        return numOfNegatives;
    }
};
