class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Step 1: Create a hashmap where
        // Key: sorted version of the string (anagram signature)
        // Value: list of words that share the same sorted key (i.e., are anagrams)
        unordered_map<string, vector<string>> mpp;

        // Step 2: Iterate over each word in the input list
        for(const string& word : strs) {
            string sortedstring = word;              // Make a copy of the original word
            sort(sortedstring.begin(), sortedstring.end()); // Sort the string alphabetically
            
            // Now the sorted string acts as the "anagram signature"
            // For example: "eat", "tea", and "ate" all become "aet"

            // Group the original word under its anagram signature
            mpp[sortedstring].push_back(word);
        }

        // Step 3: Prepare the final result by extracting values from the hashmap
        vector<vector<string>> result;

        // Each value in the map is a group of anagrams
        for (auto& anagrams : mpp) {
            result.push_back(anagrams.second); // Add the group to the result
        }

        return result; // Return the grouped anagrams
    }
};
