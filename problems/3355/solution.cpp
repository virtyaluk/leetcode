class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, int> m;

        for (const vector<int>& q: queries) {
            m[q.front()]++;
            m[q.back() + 1]--;
        }

        for (int i = 0, cur = 0; i < size(nums); i++) {
            cur += m[i];

            if (nums[i] > cur) {
                return false;
            }
        }

        return true;
    }
};