class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0,
            maxEl = *max_element(begin(nums), end(nums));
        
        for (const int& num: nums) {
            ans += maxEl - num;
        }

        return ans;
    }
};