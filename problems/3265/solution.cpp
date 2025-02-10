class Solution {
private:
    bool eq(const int& a, const int& b) {
        string sa = format("{:08}", a),
            sb = format("{:08}", b);
        int dif = 0;
        unordered_multiset<char> um(begin(sa), end(sa));
        
        for (int i = 0; i < size(sa); i++) {
            dif += sa[i] != sb[i];
            
            if (auto it = um.find(sb[i]); it != end(um)) {
                um.erase(it);
            }
        }
        
        return dif <= 2 and empty(um);
    }
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            for (int j = i + 1; j < size(nums); j++) {
                ans += eq(nums[i], nums[j]);
            }
        }
        
        return ans;
    }
};