class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitGained = -1, minBuyCost=10001;
        for(auto price:prices){
            minBuyCost = min(minBuyCost,price);
            maxProfitGained = max(maxProfitGained,price-minBuyCost);
        }
        return maxProfitGained;
    }
};
