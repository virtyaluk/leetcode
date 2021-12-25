class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int ans = -1;
        unordered_map<int, int> m;
        
        for (const int& num: A) {
            m[num]++;
        }
        
        for (auto [num, freq]: m) {
            if (freq == 1) {
                ans = max(ans, num);
            }
        }
        
        return ans;
    }
};