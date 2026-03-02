const int MOD = 1e9 + 7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq,
            partFreq;
        
        freq.reserve(size(nums) * 2);
        partFreq.reserve(size(nums) * 2);

        for (const int& num: nums) {
            freq[num]++;
        }

        for (const int& num: nums) {
            int target = num * 2,
                lCnt = partFreq[target];
            partFreq[num]++;
            int rCnt = freq[target] - partFreq[target];
            ans = (ans + (lCnt * 1ll * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};