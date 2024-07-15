class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if ((num - 3) / 3 * 3 == num - 3) {
            long long x = (num - 3) / 3;
            
            return {x, x + 1, x + 2};
        }
        
        return {};
    }
};