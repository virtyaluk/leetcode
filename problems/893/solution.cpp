class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> us;
        
        for (const string& word: words) {
            vector<string> parts(2, "");
            
            for (int i = 0; i < size(word); i++) {
                parts[i % 2].push_back(word[i]);
            }
            
            sort(begin(parts.front()), end(parts.front()));
            sort(begin(parts.back()), end(parts.back()));
            
            us.insert(parts.front() + parts.back());
        }
        
        return size(us);
    }
};


/*

acb, acb
abc
bca, bca, bca

*/