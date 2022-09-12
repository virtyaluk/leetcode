class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (int num: nums) {
            if (m.find(num) != m.end() && m[num] > 0) {
                m[num]--;
                ans++;
            } else {
                int t = k - num;
                m[t]++;
            }
        }
        
        return ans;
    }
};