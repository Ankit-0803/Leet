class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        
        // Split s into words by space
        for(char ch : s) {
            if(ch == ' ') {
                if(!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if(!word.empty()) words.push_back(word);  // add last word

        // If counts don't match, pattern cannot be followed
        if(words.size() != pattern.size()) return false;

        unordered_map<char, string> p2w;  // pattern letter -> word
        unordered_map<string, char> w2p;  // word -> pattern letter

        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            // Check existing mapping
            if(p2w.count(c)) {
                if(p2w[c] != w) return false;  // mismatch
            } else {
                p2w[c] = w;
            }
            if(w2p.count(w)) {
                if(w2p[w] != c) return false;  // mismatch
            } else {
                w2p[w] = c;
            }
        }
        return true;  // all consistent
    }
};
