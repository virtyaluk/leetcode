class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> divisors;
        int nsqrt = sqrt(n);
        
        for (int i = 1; i < nsqrt + 1; i++) {
            if (n % i == 0) {
                k--;
                
                divisors.push_back(i);
                
                if (k == 0) {
                    return i;
                }
            }
        }
        
        if (nsqrt * nsqrt == n) {
            k++;
        }
        
        int dsize = divisors.size();
        
        return k <= dsize ? n / divisors[dsize - k] : -1;
    }
};