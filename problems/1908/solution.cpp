class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int ans = 0;
        
        for (const int& num: piles) {
            ans ^= num;
        }
        
        return ans;
    }
};