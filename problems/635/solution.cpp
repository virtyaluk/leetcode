using namespace std;

class LogSystem {
private:
    multimap<string, int> mm;
    
public:
    LogSystem() {}
    
    void put(int id, string timestamp) {
        mm.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gr) {
        if (gr == "Year") {
            s = s.substr(0, 5) + "01:01:00:00:00";
            e = e.substr(0, 5) + "12:31:23:59:59";
        } else if (gr == "Month") {
            s = s.substr(0, 8) + "01:00:00:00";
            e = e.substr(0, 8) + "31:23:59:59";
        } else if (gr == "Day") {
            s = s.substr(0, 11) + "00:00:00";
            e = e.substr(0, 11) + "23:59:59";
        } else if (gr == "Hour") {
            s = s.substr(0, 14) + "00:00";
            e = e.substr(0, 14) + "59:59";
        } else if (gr == "Minute") {
            s = s.substr(0, 17) + "00";
            e = e.substr(0, 17) + "59";
        }
        
        vector<int> ans;
        
        for (auto left = mm.lower_bound(s), right = mm.upper_bound(e); left != right; left++) {
            ans.push_back(left->second);
        }
        
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */