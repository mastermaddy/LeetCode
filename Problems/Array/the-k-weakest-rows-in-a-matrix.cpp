class Solution {
private:
    class ComparisonClass {
    public:
        bool operator()(const pair<int,int> &x, const pair<int,int> &y){
            if(x.first==y.first) return x.second>y.second;
            return x.first>y.first;
        }
    };
    
    int getNumOfOnes(vector<int> &row){
        int low = 0, high = row.size()-1, index=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(row[mid]==0){
                index = mid;
                high = mid - 1;
            }
            else if(row[mid]==1){
                low = mid + 1;
            }
        }
        return (index==-1)?row.size():index;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k){
        priority_queue<pair<int, int>, vector<pair<int,int>>, ComparisonClass> pq;
        vector<int> kWeakestRowsIndices;
        for(int i=0;i<mat.size();++i){
            pq.push({getNumOfOnes(mat[i]),i});
        }
        while(k--){
            kWeakestRowsIndices.push_back(pq.top().second);
            pq.pop();
        }
        return kWeakestRowsIndices;
    }
};
