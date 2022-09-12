class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        
        return count_if(begin(items), end(items), [&](const vector<string>& item) {
            return item[idx] == ruleValue;
        });
    }
};