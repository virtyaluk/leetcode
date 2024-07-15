class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> us;
        
        sort(begin(nums), end(nums));
        
        for (int lo = 0, hi = size(nums) - 1; lo < hi;) {
            us.insert((nums[lo++] + nums[hi--]) / 2.0);
        }
        
        return size(us);
    }
};