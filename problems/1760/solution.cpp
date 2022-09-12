class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1, hi = *max_element(begin(nums), end(nums));
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(nums, mid) > maxOperations) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
    
    int check(const vector<int>& nums, int bug) {
        int ans = 0;
        
        for (const int& num: nums) {
            ans += (num - 1) / bug;
        }
        
        return ans;
    }
};