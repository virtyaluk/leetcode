const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aam = stoi(arriveAlice.substr(0, 2)),
            aad = stoi(arriveAlice.substr(3, 2)),
            alm = stoi(leaveAlice.substr(0, 2)),
            ald = stoi(leaveAlice.substr(3, 2)),
            bam = stoi(arriveBob.substr(0, 2)),
            bad = stoi(arriveBob.substr(3, 2)),
            blm = stoi(leaveBob.substr(0, 2)),
            bld = stoi(leaveBob.substr(3, 2)),
            aaD = 0,
            alD = 0,
            baD = 0,
            blD = 0;
        
        for (int i = 1, cur = 0; i <= 12; i++) {
            if (i == aam) {
                aaD = cur + aad;
            }

            if (i == alm) {
                alD = cur + ald;
            }

            if (i == bam) {
                baD = cur + bad;
            }

            if (i == blm) {
                blD = cur + bld;
            }

            cur += days[i];
        }

        if (alD < baD or blD < aaD) {
            return 0;
        }

        return min(alD, blD) - max(aaD, baD) + 1;
    }
};