struct Trie {
    string serial;
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie *root = new Trie();
        unordered_map<string, int> freq;
        vector<vector<string>> ans;
        vector<string> path;
        function<void(Trie*)> construct = [&](Trie *node) {
            if (empty(node->children)) {
                return;
            }

            vector<string> v;

            for (const auto& [folder, child]: node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }

            sort(begin(v), end(v));

            for (string& s: v) {
                node->serial += move(s);
            }

            freq[node->serial]++;
        };
        function<void(Trie*)> operate = [&](Trie *node) {
            if (freq[node->serial] > 1) {
                return;
            }

            if (not empty(path)) {
                ans.push_back(path);
            }

            for (const auto& [folder, child]: node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        for (const vector<string>& p: paths) {
            Trie *cur = root;

            for (const string& n: p) {
                if (not cur->children.count(n)) {
                    cur->children[n] = new Trie();
                }

                cur = cur->children[n];
            }
        }

        construct(root);
        operate(root);

        return ans;
    }
};