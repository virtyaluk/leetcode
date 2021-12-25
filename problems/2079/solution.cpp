class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        
        for (int i = 0, cur = capacity; i < size(plants); i++) {
            if (cur >= plants[i]) {
                ans++;
            } else {
                ans += 2 * i + 1;
                cur = capacity;
            }
            
            cur -= plants[i];
        }
        
        return ans;
    }
};