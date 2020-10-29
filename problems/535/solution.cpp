class Solution {
private:
    hash<string> hashString;
    unordered_map<unsigned long, string> store;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        unsigned long hash = hashString(longUrl);
        store[hash] = longUrl;
        
        return to_string(hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return store[stoul(shortUrl, nullptr, 0)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));