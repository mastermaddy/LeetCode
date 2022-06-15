class Solution {
public:
    int numberOfPermutations(int n){
        if(n==1) return 1;
        return n*numberOfPermutations(n-1);
    }
    
    void nextPermutation(vector<int> &nums, int &n){
        int i, j;
        for(i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){ 
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
        for(j=n-1;j>i;--j){
            if(nums[j]>nums[i]){
                break;
            }
        }
        swap(nums[j], nums[i]);
        reverse(nums.begin()+i+1, nums.end());
    }
    
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> allPermutations;
        int n = nums.size();
        int numOfAllPermutations = numberOfPermutations(n);
        sort(nums.begin(), nums.end());
        allPermutations.push_back(nums);
        for(int i=1;i<numOfAllPermutations;++i){
            nextPermutation(nums, n);
            allPermutations.push_back(nums);
        }
        return allPermutations;
    }
};
