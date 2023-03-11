class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        
        sort(begin(costs), end(costs));
        
        for (int i = 0; i < size(costs); i++) {
            if (costs[i] > coins) {
                break;
            }
            
            coins -= costs[i];
            ans++;
        }
        
        return ans;
    }
};