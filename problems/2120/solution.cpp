class Solution {
public:
    unordered_map<char, int> dirs = {{'R', 1}, {'L', -1}, {'U', -1}, {'D', 1}};
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        
        for (int i = 0; i < size(s); i++) {
            ans.push_back(helper(s, n, startPos[0], startPos[1], i));
        }
        
        return ans;
    }
    
    int helper(string& s, int n, int x, int y, int pos) {
        int ans = 0;
        
        for (int i = pos; i < size(s); i++) {
            if (s[i] == 'R') {
                y++;
            } else if (s[i] == 'L') {
                y--;
            } else if (s[i] == 'U') {
                x--;
            } else if (s[i] == 'D') {
                x++;
            }
            
            if (x < 0 or x >= n or y < 0 or y >= n) {
                return ans;
            }
            
            ans++;
        }
        
        return ans;
    }
};