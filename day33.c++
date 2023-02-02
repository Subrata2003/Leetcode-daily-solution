class Solution {
public:
    int orderMap[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.length(); i++){
            orderMap[order[i] - 'a'] = i;
        }
    
        for(int i =1;i< words.size();i++){
            if(!compare(words[i],words[i-1]))return false;
        }
        return true;
    }
    
    bool compare(string s1, string s2){
            int j = 0;
        while(j<s1.length() && j<s2.length()){
            if(s1[j] == s2[j]) j++;
            else if(orderMap[s1[j]-'a']>orderMap[s2[j]-'a']) return true;
            else return false;
        }
        if(s1.length()<s2.length())return false;
        return true;
    }
};