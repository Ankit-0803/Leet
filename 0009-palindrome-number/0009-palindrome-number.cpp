class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0 && x!=0))return false;
        long original=x;
        long reversal=0;
        //reverse the number and store it in reversal
        while(x>0){
            //take the last digit and append in reversak
            reversal=reversal*10+x%10;
            x/=10;
        }
        return reversal==original;
        
    }
};