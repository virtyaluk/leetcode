class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        
        for (int i = 0; i < size(words); i++) {
            for (int j = i + 1; j < size(words); j++) {
                ans += words[j].starts_with(words[i]) and words[j].ends_with(words[i]);
            }
        }
        
        return ans;
    }
};