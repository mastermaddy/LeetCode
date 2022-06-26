class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left = -1, maxDist = 0, seatsSize = seats.size();
        for(int i=0;i<seatsSize;++i){
            if(seats[i]==0) continue;
            if(left==-1){
                maxDist = i;
            }
            else{
                maxDist = max(maxDist, (i - left)/2);
            }
            left = i;
        }
        if(seats[seatsSize-1]==0){
            maxDist = max(maxDist, seatsSize - left - 1);
        }
        return maxDist;
    }
};
