class UndergroundSystem {
private:
    unordered_map<string, unordered_map<string, pair<int, double>>> avg;
    unordered_map<int, pair<string, int>> travels;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        travels[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (not travels.count(id)) {
            return;
        }
        
        double time = t - travels[id].second;
        string startStation = travels[id].first;
        travels.erase(id);
        
        avg[startStation][stationName].first++;
        avg[startStation][stationName].second += time;
    }
    
    double getAverageTime(string startStation, string endStation) {
        if (avg.count(startStation) and avg[startStation].count(endStation)) {
            pair<int, double> stats = avg[startStation][endStation];
            
            return stats.second / stats.first;
        }
        
        return 0.0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */