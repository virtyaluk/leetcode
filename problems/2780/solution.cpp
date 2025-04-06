class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = size(nums);
        unordered_map<int, int> um1, um2;

        for (const int& num: nums) {
            um1[num]++;
        }

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            um1[num]--;
            um2[num]++;

            if (um2[num] * 2 > i + 1 and um1[num] * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};