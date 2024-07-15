class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> occupied;
        priority_queue<long, vector<long>, greater<long>> free;
        vector<int> count(n);
        int ans = 0,
            oneRoomMax = 0;
        
        sort(begin(meetings), end(meetings));
        
        for (int i = 0; i < n; i++) {
            free.push(i);
        }
        
        for (const vector<int>& meeting: meetings) {
            int roomId = 0;
            
            while (not empty(occupied) and occupied.top().first <= meeting.front()) {
                free.push(occupied.top().second);
                occupied.pop();
            }
            
            if (not empty(free)) {
                roomId = free.top();
                free.pop();
                occupied.push({meeting.back(), roomId});
            } else {
                roomId = occupied.top().second;
                long end = (meeting.back() - meeting.front()) + occupied.top().first;
                occupied.pop();
                occupied.push({end, roomId});
            }
            
            count[roomId]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (oneRoomMax < count[i]) {
                oneRoomMax = count[i];
                ans = i;
            }
        }
        
        return ans;
    }
};