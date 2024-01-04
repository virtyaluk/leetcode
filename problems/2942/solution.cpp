class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        
        for (int i = 0; i < size(words); i++) {
            unordered_set<char> us(begin(words[i]), end(words[i]));
            
            if (us.count(x)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};