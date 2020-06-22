class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length);
        
        for (const vector<int>& update: updates) {
            int startIdx = update[0],
                endIdx = update[1],
                inc = update[2];

            ans[startIdx] += inc;
            
            if (endIdx + 1 < length) {
                ans[endIdx + 1] -= inc;
            }
        }
        
        for (int i = 1; i < length; i++) {
            ans[i] += ans[i - 1];
        }
        
        return ans;
    }
};