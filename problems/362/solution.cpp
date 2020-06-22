class HitCounter {
private:
    vector<int> line;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        line.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        auto it1 = upper_bound(begin(line), end(line), timestamp - 300),
            it2 = upper_bound(begin(line), end(line), timestamp);
        
        return distance(it1, it2);
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */