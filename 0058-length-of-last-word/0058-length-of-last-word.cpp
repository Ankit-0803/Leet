class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1; // Pointer starting at the last character of the string

        // Step 1: Skip trailing spaces at the end
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        // Step 2: Find the start index of the last word
        int start = end; // Start from the end of the last word
        while (start >= 0 && s[start] != ' ') {
            start--; // Move left until a space or beginning of string
        }

        // Step 3: Length = difference between end and start indexes
        return end - start;
    }
};
