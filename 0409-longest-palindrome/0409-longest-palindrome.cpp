class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(128,0);
        int length=0;
        bool odd=false;
        for(char c:s){
            freq[c]++;
        }
        for(int i=0; i<128; i++){
            if(freq[i]%2==0){
               length+=freq[i];
            }
            else{
               length+=freq[i]-1;
               odd=true;
            }
        }
        if(odd)return length+1;
        return length;

    }
};