class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unordered_set<int> us;
        
        for (int i = 0; i < size(nums); i++) {
            pq.push({nums[i], i});
        }
        
        while (not empty(pq)) {
            auto [num, idx] = pq.top();
            pq.pop();
            
            if (us.count(idx)) {
                continue;
            }
            
            ans += num;
            
            us.insert(idx);
            us.insert(idx + 1);
            us.insert(idx - 1);
        }
        
        return ans;
    }
};