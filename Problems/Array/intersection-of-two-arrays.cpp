class Solution {
private:
    bool isPresent(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]==target){
                return true;
            }
            else{
                if(nums[mid]>target){
                    high = mid-1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersectionSet;
        if(nums1.size()<nums2.size()){
            swap(nums1,nums2);
        }
        sort(nums1.begin(),nums1.end());
        for(auto num:nums2){
            if(isPresent(nums1,num)){
                intersectionSet.insert(num);
            }
        }
        vector<int> intersectionList(intersectionSet.begin(),intersectionSet.end());
        return intersectionList;
    }
};
