class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count = 0;
        vector<int> b(n + 1);
        
        for (int i = 0; i < n; i++) {
            int c = citations[i];
            
            if (c >= n) {
                b[n]++;
            } else {
                b[c]++;
            }
        }
        
        for (int i = n; i >= 0; i--) {
            count += b[i];
            
            if (count >= i) {
                return i;
            }
        }
        
        return 0;
    }
};