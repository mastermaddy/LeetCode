class Solution {
private:
    bool areAllRoomsVisited(vector<bool> &visited){
        for(auto roomVisited:visited){
            if(!roomVisited) return false;
        }
        return true;
    }
    void putKeysFromCurrentRoom(queue<int> &q, vector<int> keys, vector<bool> &visited){
        for(auto key:keys){
            if(!visited[key]){
                q.push(key);
                visited[key] = true;
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> roomsVisited;
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        putKeysFromCurrentRoom(roomsVisited, rooms[0], visited);
        while(!roomsVisited.empty()){
            putKeysFromCurrentRoom(roomsVisited, rooms[roomsVisited.front()], visited);
            roomsVisited.pop();
        }
        return areAllRoomsVisited(visited);
    }
};
