class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = size(nums),
            numLen = size(nums.front());
        
        for (const vector<int>& query: queries) {
            int k = query[0],
                trim = query[1];
            vector<pair<string, int>> trimmed(n);
            
            for (int i = 0; i < n; i++) {
                trimmed[i] = {nums[i].substr(numLen - trim), i};
            }
            
            sort(begin(trimmed), end(trimmed), [](pair<string, int>& a, pair<string, int>& b) {
                if (a.first < b.first) {
                    return true;
                } else if (a.first > b.first) {
                    return false;
                }
                
                return a.second < b.second;
            });
            
            ans.push_back(trimmed[k - 1].second);
        }
        
        return ans;
    }
};