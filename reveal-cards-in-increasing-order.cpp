class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int sz = deck.size();
        queue<int> q;
        vector<int> newDeck(sz);
        sort(deck.begin(),deck.end());
        for(int i=0;i<sz;++i){
            q.push(i);
        }
        for(auto card:deck){
            {
                newDeck[q.front()] = card;
                q.pop();
            }
            {
                q.push(q.front());
                q.pop();
            }
        }
        return newDeck;
    }
};
