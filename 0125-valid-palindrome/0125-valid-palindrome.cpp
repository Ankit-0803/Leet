class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            //skip all alphanumeric characters form left
            while(left<right && !isalnum(s[left]))left++;
            //skip all alphanumeric characters from right
            while(left<right && !isalnum(s[right]))right--;
            //convert to lowercase and compare
            if(tolower(s[left])!=tolower(s[right]))return false;
            left++;
            right--;
        }return true;
    }
};