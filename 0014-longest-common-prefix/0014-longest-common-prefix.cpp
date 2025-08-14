class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // No strings → no common prefix
        // Step 1: Sort the strings lexicographically
        sort(strs.begin(), strs.end());
        // Step 2: First and last strings will have the minimum common prefix
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int i = 0;
        // Step 3: Compare characters of first and last string
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        // Step 4: Return common prefix
        return first.substr(0, i);
    }
};
