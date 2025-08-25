class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //unordered_map<int, int>freq;
        vector<int>freq(26,0);
        for(char ch: magazine){
            freq[ch-'a']++;        
            }
            //freq = [2, 1, 0, 0, 0, ..., 0]
            for(char ch: ransomNote){
            freq[ch-'a']--;
            if(freq[ch-'a']<0)return false;
        }
        return true;
        }
};