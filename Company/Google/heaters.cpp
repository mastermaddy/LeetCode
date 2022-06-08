class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = INT_MIN;
        for(auto house:houses){
            auto itr = lower_bound(heaters.begin(), heaters.end(), house);
            minRadius = max(minRadius, min(itr!=heaters.begin()?house-*(itr-1):INT_MAX, itr!=heaters.end()? *itr - house:INT_MAX));
        }
        return minRadius;
    }
};
