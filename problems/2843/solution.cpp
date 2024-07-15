class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        
        for (int i = low; i <= high; i++) {
            string snum = to_string(i);
            
            if (size(snum) % 2) {
                continue;
            }
            
            int n = size(snum) / 2;
            
            if (accumulate(begin(snum), begin(snum) + n, '0') == accumulate(rbegin(snum), rbegin(snum) + n, '0')) {
                ans++;
            }
        }
        
        return ans;
    }
};