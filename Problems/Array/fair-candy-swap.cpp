class Solution {
private:
    int sum(vector<int> &array){
        int total = 0;
        for(auto element:array){
            total+=element;
        }
        return total;
    }
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = sum(aliceSizes);
        int bobSum = sum(bobSizes);
        unordered_set<int> aliceCandies;
        vector<int> candySwap;
        int difference = (aliceSum - bobSum) / 2;
        for(auto candies:aliceSizes){
            aliceCandies.insert(candies);
        }
        for (auto candies : bobSizes){
            if (aliceCandies.count(candies+difference) > 0){
                candySwap.push_back(candies + difference);
                candySwap.push_back(candies);
                break;
            }
        }
        return candySwap;
    }
};
