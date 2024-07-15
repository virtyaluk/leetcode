class Solution {
public:
    int numberCount(int a, int b) {
        int ans = 0;
        
        for (int i = a; i <= b; i++) {
            string snum = to_string(i);
            unordered_set<char> us(begin(snum), end(snum));
            
            ans += size(snum) == size(us);
        }
        
        return ans;
    }
};