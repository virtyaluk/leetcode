class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans = 1;
        
        sort(begin(coins), end(coins));
        
        for (const int& coin: coins) {
            if (coin > ans) {
                break;
            }
            
            ans += coin;
        }
        
        return ans;
    }
};

/*

[1,10,3,1]
1
1,1
3
3,1
3,1,1


*/