class Solution {
public:
    int expandaroundcentre(string& s, int left, int right){
        while(left>=0 && right<=s.size()-1 && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        if(s.empty())return "";
        int start=0;
        int end=0;
        for(int i=0; i<s.size(); i++){
        int odd=expandaroundcentre(s, i, i);
        int even=expandaroundcentre(s, i, i+1);
        int maxlength=max(odd, even);
        if(maxlength>(end-start)){
        start=i-(maxlength-1)/2;
        end=i+maxlength/2;
        }
        }
         return s.substr(start, end-start+1);
    }
};