class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusts(N,0), trusted(N,0);
        int judge = -1;
        for(auto trustPair:trust){
            trusts[trustPair[0]-1]++;
            trusted[trustPair[1]-1]++;
        }
        for(int i=0;i<N;++i){
            if(trusts[i]==0 && trusted[i]==N-1){
                if(judge==-1){
                    judge = i+1;
                }
                else{
                    judge = -1;
                    break;
                }
            }
        }
        return judge;
    }
};
