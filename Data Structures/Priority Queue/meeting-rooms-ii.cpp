int minMeetingRooms(vector<vector<int>> intervals) {
    priority_queue<int,vector<int>,greater<int>> pq;
    int count = 0;
    sort(intervals.begin(), intervals.end());
    for(auto interval:intervals){
      if(pq.empty()){
        count++;  
      }
      else{
        if(interval[0]>pq.top()){
          pq.pop();  
        }
        else{
          count++;  
        }
      }
      pq.push(interval[1]);
    }
    return count;
}



