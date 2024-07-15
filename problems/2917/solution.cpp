class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        bitset<32> ans;
        unordered_map<int, int> cnt;
        
        for (const int& num: nums) {
            bitset<32> bs(num);
            
            for (int i = 0; i < 32; i++) {
                cnt[i] += bs[i] == true;
                
                if (cnt[i] >= k) {
                    ans[i] = true;
                }
            }
        }
        
        return ans.to_ulong();
    }
};