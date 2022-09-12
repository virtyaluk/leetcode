class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> ar{a, b, c};
        
        sort(begin(ar), end(ar));
        
        if (ar[0] + ar[1] <= ar[2]) {
            return ar[0] + ar[1];
        }
        
        return (a + b + c) / 2;
    }
};