class ATM {
    vector<long> notes;
public:
    ATM() {
        notes.resize(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> need(5, 0);
        int val[5] = {20, 50, 100, 200, 500};
        for(int i = 4; i >= 0; i--) {
            int canTake = min((long)amount / val[i], notes[i]);
            need[i] += canTake;
            amount -= canTake * val[i];
        }
        if(amount > 0) return {-1};
        for(int i = 0; i < 5; i++) {
            notes[i] -= need[i];
        }
        return need;
    }
};