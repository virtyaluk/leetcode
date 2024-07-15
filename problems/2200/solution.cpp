class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans, keys;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == key) {
                keys.push_back(i);
            }
        }
        
        for (int i = 0; i < size(nums); i++) {
            // if (nums[i] == key) {
            //     continue;
            // }
            
            for (const int& j: keys) {
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        // sort(begin(ans), end(ans));
        
        return ans;
    }
};