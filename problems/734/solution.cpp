class Solution {
public:
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& similarPairs) {
        if (size(s1) != size(s2)) {
            return false;
        }
        
        unordered_map<string, unordered_set<string>> um;
        
        for (const vector<string>& sim: similarPairs) {
            um[sim[0]].insert(sim[1]);
            um[sim[1]].insert(sim[0]);
        }
        
        for (int i = 0; i < size(s1); i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            
            if (um[s1[i]].count(s2[i])) {
                continue;
            }
            
            return false;
        }
        
        return true;
    }
};