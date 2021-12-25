class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        for (const vector<int>& slot: slots1) {
            if (slot[1] - slot[0] >= duration) {
                pq.push(slot);
            }
        }
        
        for (const vector<int>& slot: slots2) {
            if (slot[1] - slot[0] >= duration) {
                pq.push(slot);
            }
        }
        
        while (pq.size() > 1) {
            vector<int> slot1 = pq.top();
            pq.pop();
            vector<int> slot2 = pq.top();
            
            int start = max(slot1[0], slot2[0]), end = min(slot1[1], slot2[1]);
            
            if (end - start >= duration) {
                return {start, start + duration};
            }
        }
        
        return {};
    }
    
    vector<int> minAvailableDuration1(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int, int> mm;
        
        for (const vector<int>& slot: slots1) {
            mm[slot[0]]++;
            mm[slot[1]]--;
        }
        
        for (const vector<int>& slot: slots2) {
            mm[slot[0]]++;
            mm[slot[1]]--;
        }
        
        int cur = 0, curStart = 0;
        
        for (auto &[start, freq]: mm) {
            if (cur + freq == 2) {
                curStart = start;
            } else if (cur == 2 and cur + freq != 2) {
                if (start - curStart >= duration) {
                    return {curStart, curStart + duration};
                }
            }
            
            cur += freq;
        }
        
        return {};
    }
};