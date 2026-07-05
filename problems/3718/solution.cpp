class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> us(begin(nums), end(nums));

        for (int i = k; k <= 100 + k; i += k) {
            if (not us.count(i)) {
                return i;
            }
        }

        return -1;
    }
};