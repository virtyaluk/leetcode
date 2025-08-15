class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = size(nums) - 1;
        unordered_map<int, int> um;

        for (const int& num: nums) {
            um[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (um[i] <= 0) {
                return false;
            }
        }

        if (um[n] != 2) {
            return false;
        }

        return true;
    }
};