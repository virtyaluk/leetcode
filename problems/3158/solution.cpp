class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> once;
        vector<int> twice;
        
        for (const int& num: nums) {
            if (not once.count(num)) {
                once.insert(num);
            } else {
                twice.push_back(num);
            }
        }
        
        int ans = empty(twice) ? 0 : twice.front();
        
        for (int i = 1; i < size(twice); i++) {
            ans ^= twice[i];
        }
        
        return ans;
    }
};