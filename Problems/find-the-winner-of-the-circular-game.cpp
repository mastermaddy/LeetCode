class Solution {
public:
    int findTheWinnerUsingQueue(int n, int k) {
        queue<int> q;
        for(int i=0;i<n;++i){
            q.push(i);
        }
        while(q.size()!=1){
            for(int i=0;i<k-1;++i){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front()+1;
    }
    int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i=1;i<=n;++i){
            winner = (winner+k)%i;
        }
        return winner + 1;
    }
};
