class SmallestInfiniteSet {
private:
    set<int> s;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int ans = *begin(s);
        
        s.erase(begin(s));
        
        return ans;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */