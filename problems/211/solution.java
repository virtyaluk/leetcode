class WordDictionary {

    /** Initialize your data structure here. */
    Map <Integer, HashSet<String>> map=new HashMap(); 
    public WordDictionary() {
       
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        int l=word.length();
        if(map.containsKey(l)){
            map.get(l).add(word);
        }
        else{
            
            HashSet<String> set=new HashSet();
            set.add(word);
            map.put(l,set);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        int l=word.length();
        if(!map.containsKey(l)){
            return false;
        }
        else{
            HashSet<String> set = map.get(l);
            int countnoDot=0;  //counter to store numbers of characters with no dot(.)
            int same=0;  //counter to store number of same characters
            for(String s:set){
                countnoDot=0;
                same=0;
                for(int i=0;i<l;i++){
                    if(word.charAt(i)!='.'){
                        countnoDot++;
                        if(word.charAt(i)==s.charAt(i)){
                            same++;
                        }
                    }
                }
                if(same==countnoDot){
                    return true;
                }
            }
            return false;
        }
        
    }
}