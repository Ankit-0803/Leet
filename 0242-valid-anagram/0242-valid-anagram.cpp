class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        // unordered_map<int, int>mpp;
        vector<int>mpp(26,0);//for lowercase letters
        for(char ch: s){
            mpp[ch-'a']++;
         }
         for(char ch:t){
            mpp[ch-'a']--;
         }
         for(int count: mpp){
        if(count!=0)return false;
         }
         return true;
        
    }
};