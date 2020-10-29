class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, m = *min_element(begin(nums), end(nums));
        
        for (const int& num: nums) {
            ans += (num - m);
        }
        
        return ans;
    }
};