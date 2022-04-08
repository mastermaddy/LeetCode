class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ticketsOfK = tickets[k];
        int timeRequired = 0;
        for(int i=0;i<tickets.size();++i){
            timeRequired+=min(tickets[i],ticketsOfK-(i>k));
        }
        return timeRequired;
    }
};
