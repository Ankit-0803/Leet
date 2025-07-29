class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            };
            j++;
        }
        //only return true if we reached the end of string s,
        // that means all elements of string s are coverend
        return i==s.size();
        
    }
};