class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0,
            cnt = 0;
        
        for (const int& num: nums) {
            if (num % 2 == 0 and num % 3 == 0) {
                total += num;
                cnt++;
            }
        }

        if (not cnt) {
            return 0;
        }

        return total / cnt;
    }
};