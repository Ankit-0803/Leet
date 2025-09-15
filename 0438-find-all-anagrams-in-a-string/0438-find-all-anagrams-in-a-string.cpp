class Solution {
public:
        bool anagrams(string q, string p){
        if(q.size()!=p.size())return false;
        vector<int>freq(26,0);
        for(char c:p){
            freq[c-'a']++;
        }
        for(char c:q){
            freq[c-'a']--;
            if(freq[c-'a']<0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        int z=p.size();
        for(int i=0; i+z<=s.size(); i++){
            string q="";
            for(int j=i; j<(i+z); j++){
                q.push_back(s[j]);
            }
        if(anagrams(p, q)==true)res.push_back(i);
 
        }
        return res;
    }
};