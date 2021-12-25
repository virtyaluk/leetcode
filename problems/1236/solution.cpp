/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    string getHostname(string url) {
        int pos = min(size(url), url.find('/', 7));
        
        return url.substr(7, pos - 7);
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        queue<string> q;
        string startHostname = getHostname(startUrl);
        
        q.push(startUrl);
        visited.insert(startUrl);
        
        while (not empty(q)) {
            string url = q.front();
            q.pop();
            
            for (string& nextUrl: htmlParser.getUrls(url)) {
                if (getHostname(nextUrl) == startHostname and not visited.count(nextUrl)) {
                    visited.insert(nextUrl);
                    q.push(nextUrl);
                }
            }
        }
        
        return {begin(visited), end(visited)};
    }
};