class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // stack to hold numbers

        for (string& token : tokens) {
            // Case 1: token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop(); // second operand
                int a = st.top(); st.pop(); // first operand
                int result = 0;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else if (token == "/") result = a / b; // truncates toward zero

                st.push(result); // push result back
            }
            // Case 2: token is a number
            else {
                st.push(stoi(token)); // convert string to int and push
            }
        }

        return st.top(); // final result
    }
};
