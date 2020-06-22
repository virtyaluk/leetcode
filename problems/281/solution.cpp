class ZigzagIterator {
private:
    queue<pair<int, vector<int>>> q;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (not empty(v1)) {
            q.push({0, v1});
        }
        
        if (not empty(v2)) {
            q.push({0, v2});
        }
    }

    int next() {
        if (hasNext()) {
            int ans = 0;
            auto [idx, v] = q.front();
            q.pop();
            
            ans = v[idx++];
            
            if (idx < size(v)) {
                q.push({idx, v});
            }
            
            return ans;
        }
        
        return -1;
    }

    bool hasNext() {
        return not empty(q);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */