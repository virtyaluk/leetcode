class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int i = 0; i < size(nums); i++) {
            pq.push({nums[i], i});
        }
        
        for (int i = 0; i < k; i++) {
            auto [num, idx] = pq.top();
            pq.pop();
            
            nums[idx] *= multiplier;
            pq.push({num * multiplier, idx});
        }
        
        return nums;
    }
};