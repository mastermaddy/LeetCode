class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonousQueue;
        vector<int> maxNumbersInGivenWindow;
        for(int i=0;i<nums.size();++i){
            while(!monotonousQueue.empty() && i-monotonousQueue.front()>=k){
                monotonousQueue.pop_front();
            }
            while(!monotonousQueue.empty() && nums[i]>nums[monotonousQueue.back()]){
                monotonousQueue.pop_back();
            }
            monotonousQueue.push_back(i);
            if(i>=k-1){
                maxNumbersInGivenWindow.push_back(nums[monotonousQueue.front()]);
            }
        }
        return maxNumbersInGivenWindow;
    }
};
