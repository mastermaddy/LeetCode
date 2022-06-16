class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaValue = 0;
        for(int left = 0, right=height.size()-1;left<right;){
            int currAreaValue = (right-left)*min(height[right], height[left]);
            maxAreaValue = max(maxAreaValue, currAreaValue);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxAreaValue;
    }
};
