class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = size(rooms),
            n = size(queries),
            j = 0;
        vector<int> ans(n);
        set<int> roomIds;
        auto cmp = [](const vector<int>& a, const vector<int>& b) { return a[1] > b[1]; };
        
        for (int i = 0; i < n; i++) {
            queries[i].push_back(i);
        }
        
        sort(begin(rooms), end(rooms), cmp);
        sort(begin(queries), end(queries), cmp);
        
        for (const vector<int>& query: queries) {
            int preferred = query[0],
                minSize = query[1],
                qIdx = query[2];
            
            for (; j < m and rooms[j][1] >= minSize; j++) {
                roomIds.insert(rooms[j][0]);
            }
            
            if (empty(roomIds)) {
                ans[qIdx] = -1;
                continue;
            }
            
            auto it = roomIds.upper_bound(preferred);
            
            if (it == begin(roomIds)) {
                ans[qIdx] = *begin(roomIds);
            } else {
                int nextVal = it == end(roomIds) ? INT_MAX : *it,
                    prevVal = *prev(it);
                ans[qIdx] = abs(prevVal - preferred) <= abs(nextVal - preferred) ? prevVal : nextVal;
            }
        }
        
        return ans;
    }
};