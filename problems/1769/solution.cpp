class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        
        for (int i = 0, count = 0, moves = 0; i < n; i++) {
            ans[i] = moves;
            count += (boxes[i] - '0');
            moves += count;
        }
        
        for (int i = n - 1, count = 0, moves = 0; i >= 0; i--) {
            ans[i] += moves;
            count += (boxes[i] - '0');
            moves += count;
        }
        
        return ans;
    }
};

// [1, 1, 0]
// [0, 1, 3]

// [0, 0, 1, 0, 1, 1]
// [0, 0, 0, 1, 2, 4]