class BrowserHistory {
private:
    list<string> history;
    list<string>::iterator it;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = begin(history);
    }
    
    void visit(string url) {
        auto toDel = it;
        toDel++;
        
        history.erase(toDel, end(history));
        history.push_back(url);
        
        it++;
    }
    
    string back(int steps) {
        while (it != begin(history) and steps--) {
            it--;
        }
        
        return *it;
    }
    
    string forward(int steps) {
        while (it != prev(end(history)) and steps--) {
            it++;
        }
        
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */