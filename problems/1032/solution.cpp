struct Trie {
    unordered_map<char, Trie*> children;
    bool end = false;
};

class StreamChecker {
private:
    Trie* root;
    vector<Trie*> pset;
public:
    StreamChecker(vector<string>& words) {
        root = new Trie();

        for (const string& w: words) {
            Trie* cur = root;

            for (const char& ch: w) {
                if (not cur->children.count(ch)) {
                    cur->children[ch] = new Trie();
                }

                cur = cur->children[ch];
            }

            cur->end = true;
        }

        pset.push_back(root);
    }
    
    bool query(char letter) {
        bool ok = false;
        vector<Trie*> cur;

        for (auto t: pset) {
            if (not t->children.count(letter)) {
                continue;
            }

            cur.push_back(t->children[letter]);

            if (t->children[letter]->end) {
                ok = true;
            }
        }

        cur.push_back(root);
        pset = cur;

        return ok;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */