class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        
        for (int i = 0; i < size(colors); i++) {
            for (int j = 0; j < size(colors); j++) {
                if (colors[i] != colors[j]) {
                    ans = max(ans, abs(i - j));
                }
            }
        }
        
        return ans;
    }
};