class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        
        sort(begin(spaces), end(spaces));
        
        for (int i = 0, j = 0; i < size(s); i++) {
            if (j < size(spaces) and spaces[j] == i) {
                ans.push_back(' ');
                j++;
            }
            
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};