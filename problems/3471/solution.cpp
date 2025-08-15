class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxEl = INT_MIN;

        for (const int& num: nums) {
            freq[num]++;
            maxEl = max(maxEl, num);
        }

        if (k == size(nums)) {
            return maxEl;
        } else if (k == 1) {
            maxEl = INT_MIN;

            for (auto [num, fr]: freq) {
                if (fr == 1) {
                    maxEl = max(maxEl, num);
                }
            }

            return maxEl == INT_MIN ? -1 : maxEl;
        } else {
            if (freq[nums.front()] == 1 and freq[nums.back()] == 1) {
                return max(
                    nums.front(),
                    nums.back()
                );
            } else if (freq[nums.front()] == 1) {
                return nums.front();
            } else if (freq[nums.back()] == 1) {
                return nums.back();
            }
        }

        return -1;
    }
};