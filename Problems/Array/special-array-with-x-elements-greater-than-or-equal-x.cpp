class Solution {
public:
    int getNumOfGreaterOrEqualNums(vector<int>& nums,int target){
        int count=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>=target){
                ++count;
            }
        }
        return count;
    }
    int specialArray(vector<int>& nums) {
       int low=0,high=nums.size();
        while(low<=high){
            int mid=(low+high)/2;
            int X=getNumOfGreaterOrEqualNums(nums,mid);
            if(X==mid){
                return X;
            }
            if(X>mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
