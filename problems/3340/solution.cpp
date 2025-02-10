class Solution {
public:
    bool isBalanced(string num) {
        int left = 0,
            right = 0;
        
        for (int i = 0; i < size(num); i++) {
            if (i % 2 == 0) {
                left += num[i] - '0';
            } else {
                right += num[i] - '0';
            }
        }
        
        return left == right;
    }
};