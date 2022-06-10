class Solution {
public:
    vector<vector<int>> getTwoSum(vector<int>& input, int left, int right, int target) {
        vector<vector<int>> twoSumOutput;
        right--;
        while (left < right) {
            int curr_sum = input[left] + input[right];
            if (curr_sum == target) {
                twoSumOutput.push_back({ input[left],input[right] });
                right--;
                left++;
                while (left < right && input[left] == input[left - 1]) {
                    left++;
                }
                while (left < right && input[right] == input[right + 1]) {
                    right--;
                }
            }
            else if (curr_sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return twoSumOutput;
    }

    bool getNSum(int N, int target, vector<int>& input, int start, int &end, vector<int> NMinusTwoSumOutput, vector<vector<int>>& NSumOutput) {
        if (end < N || N < 2) return false;
        if (N == 2) {
            vector<vector<int>> twoSumOutput = getTwoSum(input, start, end, target);
            if (twoSumOutput.size()) {
                for (auto output : twoSumOutput) {
                    NSumOutput.push_back(NMinusTwoSumOutput);
                    NSumOutput.back().insert(NSumOutput.back().end(), output.begin(), output.end());
                }
                return true;
            }
            else{
                return false;
            }
        }
        else {
            for (int i = start; i < end - N + 1; ++i) {
                if (input[i] * N > target || input[end - 1] * N < target) {
                    return false;
                }
                else {
                    NMinusTwoSumOutput.push_back(input[i]);
                    getNSum(N - 1, target - input[i], input, i + 1, end, NMinusTwoSumOutput, NSumOutput);
                    NMinusTwoSumOutput.pop_back();
                }
            }
        }
        return false;
    }

    vector<vector<int>> NSum(int N, int target, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        vector<vector<int>> NSumOutput;
        vector<int> NMinusTwoSumOutput;
        getNSum(N, target, arr, 0, sz, NMinusTwoSumOutput, NSumOutput);
        return NSumOutput;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target, int N=4) {
        return NSum(N,target,nums);
    }
};
