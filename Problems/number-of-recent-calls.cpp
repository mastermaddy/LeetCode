class RecentCounter {
private:
    queue<int> data;
public:
    RecentCounter() {   
    }
    int ping(int t, int pastRange=3000) {
        data.push(t);
        while(data.front()<t-pastRange){
            data.pop();
        }   
        return data.size();
    }
};
