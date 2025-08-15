class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isEnd = false;
};

class Solution {
private:
    void insert(const string& s, Trie* root) {
        Trie* node = root;

        for (const char& ch: s) {
            if (not node->children.count(ch)) {
                node->children[ch] = new Trie();
            }

            node = node->children[ch];
        }

        node->isEnd = true;
    }

    bool search(const string& w, Trie* root, int idx, int mismatchCount) {
        if (mismatchCount > 1) {
            return false;
        }

        if (idx >= size(w)) {
            return root->isEnd and mismatchCount == 1;
        }

        for (auto [ch, nextNode]: root->children) {
            int nextMismatchCount = mismatchCount + (ch != w[idx]);

            if (search(w, nextNode, idx + 1, nextMismatchCount)) {
                return true;
            }
        }

        return false;
    }
public:
    bool differByOne(vector<string>& dict) {
        Trie* trie = new Trie();

        for (const string& w: dict) {
            insert(w, trie);
        }

        for (const string& w: dict) {
            if (search(w, trie, 0, 0)) {
                return true;
            }
        }

        return false;
    }
};