class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freqs;
        
        for (const int& num: nums) {
            freqs[num]++;
        }
        
        for (auto [num, freq]: freqs) {
            if (freq == 1) {
                ans += num;
            }
        }
        
        return ans;
    }
};