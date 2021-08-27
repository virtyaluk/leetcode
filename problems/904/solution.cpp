class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (int i = 0, j = 0; j < size(fruits); j++) {
            um[fruits[j]]++;
            
            if (size(um) <= 2) {
                ans = max(ans, j - i + 1);
            } else {
                um[fruits[i]]--;
                
                if (not um[fruits[i]]) {
                    um.erase(fruits[i]);
                }
                
                i++;
            }
        }
        
        return ans;
    }
};