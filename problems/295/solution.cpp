class MedianFinder {
private:
    multiset<double> lo, hi;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        lo.insert(num);
        
        hi.insert(*rbegin(lo));
        lo.erase(prev(end(lo)));
        
        if (size(hi) > size(lo)) {
            lo.insert(*begin(hi));
            hi.erase(begin(hi));
        }
    }
    
    double findMedian() {
        if (size(lo) > size(hi)) {
            return *rbegin(lo);
        } else {
            return 0.5 * (*rbegin(lo) + *begin(hi));
        }
    }
};


// class MedianFinder {
// private:
//     priority_queue<int> firstHalf;
//     priority_queue<int, vector<int>, greater<>> secondHalf;
    
// public:
//     /** initialize your data structure here. */
//     MedianFinder() {}
    
//     void addNum(int num) {
//         firstHalf.push(num);
        
//         secondHalf.push(firstHalf.top());
//         firstHalf.pop();
        
//         if (size(secondHalf) > size(firstHalf)) {
//             firstHalf.push(secondHalf.top());
//             secondHalf.pop();
//         }
//     }
    
//     double findMedian() {
//         if (size(firstHalf) > size(secondHalf)) {
//             return firstHalf.top();
//         } else {
//             return 0.5 * (double) (firstHalf.top() + secondHalf.top());
//         }
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */