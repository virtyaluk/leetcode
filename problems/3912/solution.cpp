class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = size(nums);
        vector<bool> vis(n);
        vector<int> ans;

        vis.front() = vis.back() = true;

        for (int i = 1, maxEl = nums.front(); i < n; i++) {
            if (nums[i] > maxEl) {
                vis[i] = true;
            }

            maxEl = max(maxEl, nums[i]);
        }

        for (int i = n - 2, maxEl = nums.back(); i >= 0; i--) {
            if (nums[i] > maxEl) {
                vis[i] = true;
            }

            maxEl = max(maxEl, nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};