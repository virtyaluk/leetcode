class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        
        for (const string& pat: patterns) {
            ans += word.find(pat) != string::npos;
        }
        
        return ans;
    }
};