class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            // while(s[i]==' '|| s[i]==',' || s[i]==':' ||  s[i]=='.')i++;
            // while(s[j]==' '|| s[j]==',' || s[j]==':' ||  s[j]=='.')j--;
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};