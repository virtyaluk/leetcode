class Solution {
private:
    bool isNonZero(int num) {
        while (num) {
            if (num % 10 == 0) {
                return false;
            }
            
            num /= 10;
        }
        
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (isNonZero(i) and isNonZero(n - i)) {
                return {i, n - i};
            }
        }
        
        return {};
    }
};