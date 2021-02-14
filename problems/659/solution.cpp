class Solution {
public:
    bool isPossible(vector<int>& nums) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                int aLen = a.second - a.first + 1,
                    bLen = b.second - b.first + 1;
                
                return aLen > bLen;
            }
            
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (const int& num: nums) {
            while (not empty(pq) and pq.top().second + 1 < num) {
                auto [seqStart, seqEnd] = pq.top();
                pq.pop();
                
                if (seqEnd - seqStart + 1 < 3) {
                    return false;
                }
            }
            
            if (empty(pq) or pq.top().second == num) {
                pq.push({num, num});
            } else {
                auto [seqStart, ignore] = pq.top();
               
                pq.pop();
                pq.push({seqStart, num});
            }
        }
        
        while (not empty(pq)) {
            auto [seqStart, seqEnd] = pq.top();
            pq.pop();
            
            if (seqEnd - seqStart + 1 < 3) {
                return false;
            }
        }
        
        return true;
    }
};