class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        
        for (const string& word: words) {
            stringstream ss(word);
            string token;
            
            while (getline(ss, token, separator)) {
                if (size(token)) {
                    ans.push_back(token);
                }
            }
        }
        
        return ans;
    }
};