class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0,
            n = size(nums);

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> odd,
                even;
            
            for (int j = i; j < n; j++) {
                auto &c = (nums[j] & 1) ? odd : even;
                c[nums[j]]++;

                if (size(odd) == size(even)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};