class FSEntry {
public:
    bool isDir = false;
    string fContents = "", name;
    unordered_map<string, FSEntry*> m;
    
    FSEntry(bool dir, string name) : isDir{dir}, name{name} {}
    
    FSEntry* mkdir(string name) {
        if (not m[name]) {
            m[name] = new FSEntry(true, name);
        }
        
        return m[name];
    }
    
    FSEntry* cd(string name) {
        return m[name];
    }
    
    vector<string> ls() {
        vector<string> ans;
        
        for (auto [name, ignore]: m) {
            ans.push_back(name);
        }
        
        sort(begin(ans), end(ans));
        
        return ans;
    }
    
    void write(string contents) {
        isDir = false;
        fContents += contents;
    }
};

class FileSystem {
private:
    FSEntry *fs = new FSEntry(true, "");
    
    vector<string> getPath(string path) {
        vector<string> ans;
        istringstream iss(path);
        string token;
        
        while (getline(iss, token, '/')) {
            ans.push_back(token);
        }
        
        return ans;
    }

public:
    FileSystem() {
        fs->mkdir("");
    }
    
    vector<string> ls(string path) {
        FSEntry *curFS = fs;
        
        for (const string& name: getPath(path)) {
            curFS = curFS->cd(name);
        }
        
        if (not curFS->isDir) {
            return {curFS->name};
        }
        
        return curFS->ls();
    }
    
    void mkdir(string path) {
        FSEntry *curFS = fs;
        
        for (const string& name: getPath(path)) {
            curFS = curFS->mkdir(name);
        }
    }
    
    void addContentToFile(string filePath, string content) {
        FSEntry *curFS = fs;
        
        for (const string& name: getPath(filePath)) {
            curFS = curFS->mkdir(name);
        }
        
        curFS->write(content);
    }
    
    string readContentFromFile(string filePath) {
        FSEntry *curFS = fs;
        
        for (const string& name: getPath(filePath)) {
            curFS = curFS->cd(name);
        }
        
        return curFS->fContents;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */