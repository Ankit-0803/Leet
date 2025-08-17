class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";    // To store the final binary sum
        int i = a.size() - 1;  // Pointer for string a (starting from last digit)
        int j = b.size() - 1;  // Pointer for string b
        int carry = 0;         // To store carry during addition

        // Loop until both strings are processed OR carry is left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;   // Start with carry from previous step
            if (i >= 0) sum += a[i--] - '0';  // Convert char to int and add
            if (j >= 0) sum += b[j--] - '0';

            result.push_back((sum % 2) + '0'); // Append the current bit
            carry = sum / 2;                   // Update carry
        }
        reverse(result.begin(), result.end()); // Since we added from right to left
        return result;
    }
};
