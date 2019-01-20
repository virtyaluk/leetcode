class Solution {
private:
    long long getCost(const vector<int>& nums, const vector<int>& cost, const int target) {
        long long ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            ans += 1l * cost[i] * abs(nums[i] - target);
        }
        
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = getCost(nums, cost, nums.front());
        int lo = *min_element(begin(nums), end(nums)),
            hi = *max_element(begin(nums), end(nums));
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long cost1 = getCost(nums, cost, mid),
                cost2 = getCost(nums, cost, mid + 1);
            ans = min(cost1, cost2);
            
            if (cost1 > cost2) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return ans;
    }
};