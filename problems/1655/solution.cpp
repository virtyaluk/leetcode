class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        if (accumulate(begin(quantity), end(quantity), 0) > size(nums)) {
            return false;
        }
        
        unordered_map<int, int> freqs;
        vector<int> freq;
        
        for (const int& num: nums) {
            freqs[num]++;
        }
        
        for (auto [num, cnt]: freqs) {
            freq.push_back(cnt);
        }
        
        sort(begin(freq), end(freq), greater<>());
        sort(begin(quantity), end(quantity), greater<>());
        
        return dfs(freq, quantity, 0);
    }
    
    bool dfs(vector<int>& freq, vector<int>& quantity, int idx) {
        if (idx >= size(quantity)) {
            return true;
        }
        
        for (int i = 0; i < size(freq); i++) {
            if (quantity[idx] > freq[i]) {
                continue;
            }
            
            freq[i] -= quantity[idx];
            
            if (dfs(freq, quantity, idx + 1)) {
                return true;
            }
            
            freq[i] += quantity[idx];
        }
        
        return false;
    }
};