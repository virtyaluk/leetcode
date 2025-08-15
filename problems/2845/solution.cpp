class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        unordered_map<int, int> um{{0, 1}};

        for (int i = 0, pref = 0; i < size(nums); i++) {
            pref += nums[i] % modulo == k;
            ans += um[(pref - k + modulo) % modulo];
            um[pref % modulo]++;
        }

        return ans;
    }
};