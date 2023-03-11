class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> um;
        string ans, token;
        istringstream iss(s);
        
        while (getline(iss, token, ' ')) {
            int idx = token.back() - '0';
            
            token.pop_back();
            um[idx] = token;
        }
        
        for (int i = 1; i <= size(um); i++) {
            ans += um[i];
            
            if (i != size(um)) {
                ans.push_back(' ');
            }
        }
        
        return ans;
    }
};