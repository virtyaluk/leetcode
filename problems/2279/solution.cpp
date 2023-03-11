class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans = 0;
        vector<int> bags;
        
        for (int i = 0; i < size(capacity); i++) {
            int free = capacity[i] - rocks[i];
            
            if (free == 0) {
                ans++;
            } else {
                bags.push_back(abs(free));
            }
        }
        
        sort(begin(bags), end(bags));
        
        for (int i = 0; i < size(bags) and bags[i] <= additionalRocks; i++) {
            additionalRocks -= bags[i];
            ans += additionalRocks >= 0;
        }
        
        return ans;
    }
};