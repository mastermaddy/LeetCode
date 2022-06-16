class Solution {
public:
    int trap(vector<int>& height) {
        int waterTrapped = 0, lmax = 0, rmax = 0;
        for(int left = 0, right = height.size()-1;left<right;){
            lmax = height[left]<lmax?lmax:height[left];
            rmax = height[right]<rmax?rmax:height[right];
            if(lmax<rmax){
                waterTrapped += (lmax - height[left]);
                left++;
            }
            else{
                waterTrapped += (rmax - height[right]);
                right--;
            }
        }
        return waterTrapped;
    }
};
