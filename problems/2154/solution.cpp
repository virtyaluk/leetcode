class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> us(begin(nums), end(nums));
        
        while (us.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};