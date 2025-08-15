class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> um;

        for (const int& num: nums) {
            um[num]++;

            if (um[num] > 2) {
                return false;
            }
        }

        return true;
    }
};