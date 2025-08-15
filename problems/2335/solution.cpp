class Solution {
public:
    int fillCups(vector<int>& amount) {
        int mx = 0,
            sum = 0;
        
        for (const int& num: amount) {
            mx = max(mx, num);
            sum += num;
        }

        return max(mx, (sum + 1) / 2);
    }
};