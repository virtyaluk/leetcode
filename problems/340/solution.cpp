class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        unordered_map<char, int> dist;
        
        for (int left = 0, right = 0; right < size(s); right++) {
            dist[s[right]]++;
            
            while (size(dist) > k) {
                dist[s[left]]--;
                
                if (dist[s[left]] <= 0) {
                    dist.erase(s[left]);
                }
                
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};