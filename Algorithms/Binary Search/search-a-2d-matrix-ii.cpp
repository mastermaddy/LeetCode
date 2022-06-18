class Solution {
public:
     bool vectorBinarySearch(vector<int>& array, int& target, int left, int right){
        if(right>=left){
            int mid = left + (right-left)/2;
            if(array[mid]==target)
                return true;
            else{
                if(array[mid]<target) 
                    return vectorBinarySearch(array, target, mid+1, right);
                else
                    return vectorBinarySearch(array, target, left, mid-1);
            }
        }
        return false;
    }
    
    bool matrixBinarySearch(vector<vector<int>>& matrix, int& target, int start, int end, int& left, int& right){
        if(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[mid][left]<= target && matrix[mid][right]>=target){
                if(vectorBinarySearch(matrix[mid], target, left, right)) 
                    return true;
            }
            return matrixBinarySearch(matrix, target, mid+1, end, left, right) || matrixBinarySearch(matrix, target, start, mid-1, left, right);
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        return matrixBinarySearch(matrix, target, start, end, left, right);
    }
};
