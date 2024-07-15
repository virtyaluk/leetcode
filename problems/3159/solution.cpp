class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans, idxs;
        
        for (int i = 0; i < size(nums); i++) {
            if (x == nums[i]) {
                idxs.push_back(i);
            }
        }
        
        for (const int& q: queries) {
            ans.push_back(q - 1 < size(idxs) ? idxs[q - 1] : -1);
        }
        
        return ans;
    }
};