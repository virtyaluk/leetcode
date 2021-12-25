class Solution {
public:
    string longestDupSubstring(string s) {
        int left=1, right=s.length();
        
        int mid=0, ans=-1;
        while(left<right){
            mid = left+(right-left)/2;
            int index=rabin_karp(mid, s);
            if(index!=-1){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        
        int start=rabin_karp(left-1, s);
        if(start==-1) return "";
        return s.substr(start, left-1);
    }
    
    int rabin_karp(int length, string s){
        unordered_set<long> set;
        long hashvalue=0;
        long modulo=100000000007;
        long power=19260817;
        int size = length;
        long finalPower=1;
        
        for(int i=0; i<size-1; i++){
            finalPower *= power;
            finalPower %= modulo;
        }
        
        for(int i=s.length()-1; i>=0; i--){
            if(length==0){
                hashvalue = (hashvalue - ((s[i+size]-'a'+1)*finalPower)%modulo + modulo)%modulo;
                hashvalue = ((hashvalue*power)%modulo + (s[i]-'a'+1))%modulo;
                if(set.find(hashvalue)==set.end()){
                    set.insert(hashvalue);
                }else{
                    return i;
                }
            }else{
                hashvalue = ((hashvalue*power)%modulo + ((s[i]-'a'+1)))%modulo;
                length--;
                if(length==0){
                    set.insert(hashvalue);
                }
            }
        }
        
        return -1;
    }
};