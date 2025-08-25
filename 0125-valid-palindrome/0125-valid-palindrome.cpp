class Solution {
public:
    bool isPalindrome(string s) {
        string sfinal="";
        for(char c:s){
            if(isalnum(c)){
                sfinal+=tolower(c);
            }
        }
        int n=sfinal.size();
        int i=0, j=n-1;
        while(i<j){
            if(sfinal[i]!=sfinal[j]){
            return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};