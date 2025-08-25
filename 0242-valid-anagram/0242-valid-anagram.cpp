class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<int, int>mpp;
        for(char ch: s){
            mpp[ch-'a']++;
         }
         for(char ch:t){
            mpp[ch-'a']--;
         }
         for(char ch:s){
            if(mpp[ch-'a']!=0)return false;
         }
         return true;
        
    }
};