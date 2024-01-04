class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        for (auto [ignore, cnt]: um) {
            pairs += cnt / 2;
        }
        
        return {pairs, (int) size(nums) - pairs * 2};
    }
};