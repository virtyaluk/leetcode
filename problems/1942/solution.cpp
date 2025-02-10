class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int curSeat = 0,
            targetArrival = times[targetFriend].front();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        set<int> availChairs;
        
        sort(begin(times), end(times));
        
        for (const vector<int>& t: times) {
            int arrival = t.front(),
                leaving = t.back(),
                targetSeat;
            
            while (not empty(pq) and pq.top().first <= arrival) {
                availChairs.insert(pq.top().second);
                pq.pop();
            }
            
            if (not empty(availChairs)) {
                targetSeat = *begin(availChairs);
                
                availChairs.erase(begin(availChairs));
            } else {
                targetSeat = curSeat++;
            }
            
            if (targetArrival == arrival) {
                return targetSeat;
            }
                
            pq.push({leaving, targetSeat});
        }
        
        return -1;
    }
};

/*

5=0


*/