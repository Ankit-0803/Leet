class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //unordered_map<int, int>mpp;
        vector<int>mpp(26,0);
        for(char ch: magazine){
            mpp[ch-'a']++;        
            }
        for(char ch: ransomNote){
            mpp[ch-'a']--;
            if(mpp[ch-'a']<0)return false;
        }
        return true;
        }
};