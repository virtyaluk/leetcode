class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        for (auto [_, cnt]: um) {
            if (cnt == 1) {
                return -1;
            }
            
            ans += ceil((double) cnt / 3);
        }
        
        return ans;
    }
};