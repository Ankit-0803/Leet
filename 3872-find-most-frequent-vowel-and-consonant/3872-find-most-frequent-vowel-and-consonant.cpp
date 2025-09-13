class Solution{
public:
    int maxFreqSum(string s){
        int maxV=0,maxC=0;
        unordered_map<char,int>freq;
        for(char c:s){
            int count=++freq[c];
            if(isVowel(c)) maxV=max(maxV,count);
            else maxC=max(maxC,count);
        }
        return maxV+maxC;
    }
private:
    bool isVowel(char c){
        static const string vowels="aeiou";
        return vowels.find(c)!=string::npos;
    }
};
