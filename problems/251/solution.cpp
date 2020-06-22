class Vector2D {
private:
    vector<vector<int>>& v;
    int i = 0, j = 0;

public:
    Vector2D(vector<vector<int>>& vec): v{vec} {
    }
    
    int next() {
        hasNext();

        return v[i][j++];
    }
    
    bool hasNext() {
        while (i < size(v) and size(v[i]) == j) {
            i++;
            j = 0;
        }
        
        return i < size(v);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
