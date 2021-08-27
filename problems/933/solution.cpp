class RecentCounter {
private:
    vector<int> window;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        window.push_back(t);
        
        while (!window.empty()) {
            if (window.front() < t - 3000) {
                window.erase(window.begin());
            } else {
                break;
            }
        }
        
        return window.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */