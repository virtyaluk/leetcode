class MovieRentingSystem {
private:
    unordered_map<int, unordered_map<int, int>> shop;
    unordered_map<int, set<vector<int>>> movie;
    set<vector<int>> st;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const vector<int>& e: entries) {
            shop[e[0]][e[1]] = e[2];
            movie[e[1]].insert({e[2], e[0]});
        }
    }
    
    vector<int> search(int m) {
        vector<int> ans;
        int idx = 0;

        for (auto& x: movie[m]) {
            if (idx++ == 5) {
                break;
            }

            ans.push_back(x[1]);
        }

        return ans;
    }
    
    void rent(int s, int m) {
        int price = shop[s][m];
        
        movie[m].erase({price, s});
        st.insert({price, s, m});
    }
    
    void drop(int s, int m) {
        int price = shop[s][m];

        movie[m].insert({price, s});
        st.erase({price, s, m});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int idx = 0;

        for (const vector<int>& x: st) {
            if (idx++ == 5) {
                break;
            }

            ans.push_back({x[1], x[2]});
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */