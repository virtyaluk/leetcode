class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0,
            maxFreq = 0;
        unordered_map<int, int> freq;
        
        for (const int& num: nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
        
        for (auto [_, fr]: freq) {
            if (fr == maxFreq) {
                ans += maxFreq;
            }
        }
        
        return ans;
    }
};