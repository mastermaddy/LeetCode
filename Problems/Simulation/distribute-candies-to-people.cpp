class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> candiesDistributed(num_people, 0);
        int curr_candies = 1, curr_person = 0;
        while (candies > 0) {
            candiesDistributed[curr_person] += min(curr_candies, candies);
            candies -= curr_candies;
            curr_person = (curr_person + 1) % num_people;
            curr_candies++;
        }
        return candiesDistributed;
    }
};