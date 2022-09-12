class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> all = {allowed.begin(), allowed.end()};
        
        return count_if(words.begin(), words.end(), [&](string& word) {
            return all_of(word.begin(), word.end(), [&](char& ch) {
                return all.find(ch) != all.end();
            });
        });
    }
};