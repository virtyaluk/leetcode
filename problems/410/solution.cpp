class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = INT_MIN, hi = 0;
        
        for (const int& num: nums) {
            lo = max(lo, num);
            hi += num;
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(nums, m, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    bool check(vector<int>& nums, int m, int cap) {
        int curCap = 0;
        m--;
        
        for (const int& num: nums) {
            if (curCap + num <= cap) {
                curCap += num;
            } else {
                curCap = num;
                m--;
            }
        }
        
        return m >= 0;
    }
};