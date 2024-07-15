class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        vector<bitset<32>> cands;
        
        for (const int& num: candidates) {
            cands.push_back(bitset<32>(num));
        }
        
        for (int i = 0; i < 32; i++) {
            int cur = 0;
            
            for (const bitset<32>& bs: cands) {
                cur += bs[i];
            }
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};