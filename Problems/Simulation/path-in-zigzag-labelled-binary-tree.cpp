#include <cmath>
#include <vector>
#include <algorithm>

class Solution {
public:
    int getLabel(int currLabel, int currDirection, int currHeight) {
        return (pow(2, currHeight - 1) + pow(2, currHeight) - currLabel - 1) / 2;
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> returnedPath;
        int currDirection = 0, currHeight = 1;

        while (pow(2, currHeight) <= label) {
            currDirection = 1 - currDirection;
            currHeight++;
        }

        while (currHeight > 0) {
            returnedPath.push_back(label);
            label = getLabel(label, currDirection, currHeight);
            currDirection = 1 - currDirection;
            currHeight--;
        }

        reverse(returnedPath.begin(), returnedPath.end());
        return returnedPath;
    }
};
