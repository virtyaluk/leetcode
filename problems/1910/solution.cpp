class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        
        for (char ch: s) {
            ans.push_back(ch);
            
            if (size(ans) >= size(part) and ans.find(part) != string::npos) {
                for (int i = 0; i < size(part); i++) {
                    ans.pop_back();
                }
            }
        }
        
        return ans;
    }
};