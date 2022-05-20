class Solution {
    public int countTriplets(int[] arr) {
        return noOfTriplets(arr, arr.length);
    }
    
    static int lg = 31;
    
    static class TrieNode {
        TrieNode children[]; 
        int indexesSum; 
        int indixesNum; 

        TrieNode() { 
            children = new TrieNode[2]; 
            
            this.children[0] = null;
            this.children[1] = null;
            
            this.indexesSum = 0; 
            this.indixesNum = 0; 
        } 
    };
    
    static void insert(TrieNode node, int num, int index) { 
        for (int bits = lg; bits >= 0; bits--) {
            int currBit = (num >> bits) & 1;
            
            if (node.children[currBit] == null) { 
                node.children[currBit] = new TrieNode(); 
            }
            
            node = node.children[currBit]; 
        }
        
        node.indexesSum += index;
        node.indixesNum++;
    }
    
    static int query(TrieNode node, int num, int index) {
        for (int bits = lg; bits >= 0; bits--) {
            int currBit = (num >> bits) & 1;
            
            if (node.children[currBit] == null) {
                return 0;
            }
            
            node = node.children[currBit];
        }
        
        int sz = node.indixesNum;
        int sum = node.indexesSum;
        int ans = (sz * index) - (sum);
        
        return ans;
    }
    
    static int noOfTriplets(int arr[], int n) {
        int currXor = 0;
        int numberOfTriplets = 0;
        TrieNode root = new TrieNode();
        
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            
            insert(root, currXor, i);
            
            currXor ^= x;
            numberOfTriplets += query(root, currXor, i);
        }
        
        return numberOfTriplets;
    } 
}