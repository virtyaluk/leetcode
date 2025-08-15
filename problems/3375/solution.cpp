class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (*min_element(begin(nums), end(nums)) < k) {
            return -1;
        }
        
        unordered_set<int> us(begin(nums), end(nums));

        us.erase(k);

        return size(us);
    }
};