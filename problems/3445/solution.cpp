class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](const int& a, const int& b) -> int {
            return ((a & 1) << 1) | (b & 1);
        };

        int n = size(s),
            ans = INT_MIN;
        
        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b) {
                    continue;
                }

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int freqA = 0,
                    freqB = 0,
                    prevA = 0,
                    prevB = 0,
                    left = -1;
                
                for (int right = 0; right < n; right++) {
                    freqA += (s[right] == a);
                    freqB += (s[right] == b);

                    while (right - left >= k and freqB - prevB >= 2) {
                        int leftStatus = getStatus(prevA, prevB);
                        best[leftStatus] = min(best[leftStatus], prevA - prevB);
                        left++;
                        prevA += (s[left] == a);
                        prevB += (s[left] == b);
                    }

                    int rightStatus = getStatus(freqA, freqB);

                    if (best[rightStatus ^ 0b10] != INT_MAX) {
                        ans = max(ans, freqA - freqB - best[rightStatus ^ 0b10]);
                    }
                }
            }
        }

        return ans;
    }
};