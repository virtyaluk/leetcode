class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> dict = {{' ', ' '}};
        string ans;
        
        for (const char& ch: key) {
            if (dict.count(ch)) {
                continue;
            }
            
            dict[ch] = 'a' + size(dict) - 1;
        }
        
        for (const char& ch: message) {
            ans.push_back(dict[ch]);
        }
        
        return ans;
    }
};