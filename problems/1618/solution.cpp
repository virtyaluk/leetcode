/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int lo = 0, hi = size(fonts) - 1;
        unordered_map<char, int> freq;
        
        for (const char& ch: text) {
            freq[ch]++;
        }
        
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2,
                height = fontInfo.getHeight(fonts[mid]),
                width = getWidth(freq, fonts[mid], fontInfo, w);
            
            if (height <= h and width <= w) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return getWidth(freq, fonts[lo], fontInfo, w) <= w ? fonts[lo] : -1;
    }
    
    int getWidth(unordered_map<char, int>& freq, int fontSize, FontInfo& fontInfo, int& width) {
        int ans = 0;
        
        for (auto [ch, fr]: freq) {
            if (ans > width) {
                return INT_MAX;
            }
            
            ans += fontInfo.getWidth(fontSize, ch) * fr;
        }
        
        return ans;
    }
};