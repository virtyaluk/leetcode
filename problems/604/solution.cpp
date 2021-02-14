class StringIterator {
private:
    vector<pair<char, int>> vpci;
    int idx = 0;
public:
    StringIterator(string s) {
        int n = size(s), i = 0;
        
        while (i < n) {
            int cnt = 0;
            char ch = s[i++];
            
            while (i < n and isdigit(s[i])) {
                cnt = cnt * 10 + (s[i++] - '0');
            }
            
            vpci.push_back({ch, cnt});
        }
    }
    
    char next() {
        char ans = ' ';
        
        if (hasNext()) {
            ans = vpci[idx].first;
            vpci[idx].second--;
            
            if (not vpci[idx].second) {
                idx++;
            }
        }
        
        return ans;
    }
    
    bool hasNext() {
        return idx < size(vpci) and vpci[idx].second > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */