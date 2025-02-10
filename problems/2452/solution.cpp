class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for (const string& q: queries) {
            for (const string word: dictionary) {
                int edits = 0;
                
                if (size(q) != size(word)) {
                    continue;
                }
                
                for (int i = 0; i < size(word); i++) {
                    edits += q[i] != word[i];
                }
                
                if (edits <= 2) {
                    ans.push_back(q);
                    
                    break;
                }
            }
        }
        
        return ans;
    }
};