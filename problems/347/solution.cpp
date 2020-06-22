class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> ans;
        unordered_map<int, int> freqs;
        vector<vector<int>> buckets(n + 1);
        
        for (const int& num: nums) {
            freqs[num]++;
        }
        
        for (auto &[num, freq]: freqs) {
            buckets[freq].push_back(num);
        }
        
        for (int i = n; i >= 0 and k > 0; i--) {
            while (not empty(buckets[i]) and k > 0) {
                ans.push_back(buckets[i].back());
                buckets[i].pop_back();
                k--;
            }
        }
        
        return ans;
    }
};