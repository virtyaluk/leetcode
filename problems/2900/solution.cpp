class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        
        ans.push_back(words.front());
        
        for (int i = 1, prev = groups.front(); i < size(words); i++) {
            if (groups[i] != prev) {
                ans.push_back(words[i]);
                prev = groups[i];
            }
        }
        
        return ans;
    }
};