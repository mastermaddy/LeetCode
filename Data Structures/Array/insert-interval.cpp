class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval){
        vector<vector<int>> updatedIntervals;
        int index = 0, intervalsSize = intervals.size();
        while(index<intervalsSize && intervals[index][1]<newInterval[0]){
            updatedIntervals.push_back(intervals[index]);
            index++;
        }
        while(index<intervalsSize && intervals[index][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        updatedIntervals.push_back(newInterval);
        while(index<intervalsSize){
            updatedIntervals.push_back(intervals[index++]);
        }
        return updatedIntervals;
    }
};
