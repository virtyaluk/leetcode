class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        for (auto [ignore, cnt]: um) {
            if (cnt % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};