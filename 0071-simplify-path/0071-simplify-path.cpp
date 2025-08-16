class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st; // stack to store valid directory names
        stringstream ss(path);
        string token;
        // Step 1: Split by "/"
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty or current directory
                continue;
            } 
            else if (token == "..") {
                // Go back one directory if possible
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            else {
                // Valid directory name → push
                st.push_back(token);
            }
        }
        // Step 2: Build the result from stack
        if (st.empty()) return "/";
        string result = "";
        for (string& dir : st) {
            result += "/" + dir;
        }
        return result;
    }
};
// string path = "/a/./b/../../c/";
// "" → ignore.
// "a" → push → st = ["a"].
// "." → ignore.
// "b" → push → st = ["a", "b"].
// ".." → pop → st = ["a"].
// ".." → pop → st = [].
// "c" → push → st = ["c"].
// "" → ignore.