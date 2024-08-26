class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        
        for (int i = 0, n = size(colors); i < n; i++) {
            if (colors[i] != colors[(n + i - 1) % n] and colors[i] != colors[(n + i + 1) % n]) {
                ans++;
            } 
        }
        
        return ans;
    }
};