class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int curMin = INT_MAX, curMax = INT_MIN, a, b;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        for (int i = 0; i < size(nums); i++) {
            pq.push({nums[i][0], i, 0});
            curMin = min(curMin, nums[i][0]);
            curMax = max(curMax, nums[i][0]);
        }
        
        a = curMin, b = curMax;
        
        while (not empty(pq)) {
            auto [val, k, idx] = pq.top();
            pq.pop();
            
            if (idx + 1 < size(nums[k])) {
                int nidx = idx + 1;
                
                pq.push({nums[k][nidx], k, nidx});
                
                curMin = get<0>(pq.top());
                curMax = max(curMax, nums[k][nidx]);
                
                if (b - a > curMax - curMin) {
                    a = curMin;
                    b = curMax;
                }
            } else {
                break;
            }
        }
        
        return {a, b};
    }
};