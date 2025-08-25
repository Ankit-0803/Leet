class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char, char>mppST;
        unordered_map<char, char>mppTS;
        for(int i=0; i<s.size(); i++){
            char c1=s[i], c2=t[i];
            //if c1 already mapped check consistency
            if(mppST.find(c1)!=mppST.end()){
                if(mppST[c1]!=c2)return false;
            }
            else{
             mppST[s[i]]=t[i];
            }
            //if c2 already mapped check consistency
            if(mppTS.find(c2)!=mppTS.end()){
                if(mppTS[c2]!=c1)return false;
            }else
            {
             mppTS[c2]=c1;
            }
        }
        return true;
    }
};