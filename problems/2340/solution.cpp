class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        auto [minEl, maxEl] = minmax_element(begin(nums), end(nums));
        int ans = (minEl - begin(nums)) + (end(nums) - maxEl - 1);
        
        if (minEl > maxEl) {
            ans--;
        }
        
        return ans;
    }
};