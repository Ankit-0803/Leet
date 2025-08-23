class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26);
        //count characters in magazine
        for(char ch: magazine){
            freq[ch-'a']++;
        }
        for(char ch:ransomNote){
            if(freq[ch-'a']==0)return false;
            freq[ch-'a']--;
        }
        return true;
    }
};