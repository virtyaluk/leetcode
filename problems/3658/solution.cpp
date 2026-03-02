class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0,
            sumEven = 0;
        
        for (int i = 0, start = 0; i < n; i++) {
            sumOdd += ++start;
            sumEven += ++start;
        }
        
        return gcd(sumOdd, sumEven);
    }
};