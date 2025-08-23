class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;  // current sign for the number
        stack<pair<int,int>> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // adjust for the outer loop increment
                sum += num * sign;
                sign = 1; // reset sign after using
            }
            else if (c == '+') {
                sign = 1; // next number is positive
            }
            else if (c == '-') {
                sign = -1; // next number is negative
            }
            else if (c == '(') {
                // push current sum and sign before '('
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if (c == ')') {
                auto [prevSum, prevSign] = st.top();
                st.pop();
                sum = prevSum + prevSign * sum;
            }
            // ignore spaces
        }
        return sum;
    }
};
