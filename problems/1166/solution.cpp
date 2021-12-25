class TrieNode {
public:
    TrieNode(int v = 0): val{v} {}
    
    unordered_map<string, TrieNode*> children;
    int val;
};

class FileSystem {
private:
    TrieNode *root = nullptr;
    
    vector<string> getFoldersList(string& path) {
        vector<string> folders;
        istringstream iss(path);
        string token;
        
        while (getline(iss, token, '/')) {
            if (not empty(token)) {
                folders.push_back(token);
            }
        }
        
        
        return folders;
    }
    
    TrieNode* find(const vector<string>& foldersList) {
        TrieNode *node = root;
        
        for (const string& folder: foldersList) {
            if (not node->children.count(folder)) {
                return nullptr;
            }
            
            node = node->children[folder];
        }
        
        return node;
    }
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    bool createPath(string path, int value) {
        vector<string> folders = getFoldersList(path);
        string targetFolder = folders.back();
        
        folders.pop_back();
        TrieNode *node = find(folders);
        
        if (not node or node->children.count(targetFolder)) {
            return false;
        }
        
        node->children[targetFolder] = new TrieNode(value);
    
        return true;
    }
    
    int get(string path) {
        vector<string> folders = getFoldersList(path);
        TrieNode *node = find(folders);
        
        if (not node) {
            return -1;
        }
        
        return node->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */