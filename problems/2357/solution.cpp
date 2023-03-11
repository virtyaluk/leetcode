class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us{begin(nums), end(nums)};
        us.erase(0);
        
        return size(us);
    }
};