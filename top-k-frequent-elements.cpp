class Solution {
private:
    struct greaterValue{
        bool operator()(const pair<int,int> &x, const pair<int, int> &y){
            return x.second>y.second;
        }
    };
private:
    unordered_map<int, int> uMap;
    vector<int> topKFrequentElements;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greaterValue> pq;
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        for(auto num:nums){
            uMap[num]++;
        }
        for(auto element:uMap){
            pq.push(element);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            topKFrequentElements.push_back(pq.top().first);
            pq.pop();
        }
        reverse(topKFrequentElements.begin(), topKFrequentElements.end());
        return topKFrequentElements;
    }
};

