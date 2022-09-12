class OrderedStream {
public:
    vector<string> s;
    int ptr;
    OrderedStream(int n) {
        s = vector<string>(n + 2);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> ans;
        
        s[id] = value;
        
        if (id == ptr) {
            while (s[ptr].size() > 0) {
                ans.push_back(s[ptr]);
                ptr++;
            }
        }
        
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */