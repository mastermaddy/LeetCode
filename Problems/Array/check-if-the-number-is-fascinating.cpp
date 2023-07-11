class Solution {
public:
    bool isFascinating(int n) {
        vector<bool> digitsExist(9, false);
        string concatString = to_string(n) + to_string(2 * n) + to_string(3 * n);

        for (char digit : concatString) {
            int index = digit - '1';
            if (digit == '0' || digitsExist[index]) {
                return false;
            }
            digitsExist[index] = true;
        }

        return true;
    }
};