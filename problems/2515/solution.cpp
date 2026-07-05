class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = size(words),
            n = size(words);

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, n - dist));
            }
        }
        
        return ans < n ? ans : -1;
    }
};