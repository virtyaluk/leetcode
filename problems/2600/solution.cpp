class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k < numOnes) {
            return k;
        }
        
        int ans = numOnes;
        k -= numOnes;
        k -= numZeros;
        
        if (k > 0) {
            ans -= k;
        }
        
        return ans;
    }
};