class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>res(n,0);
          for (int i = n - 1; i >= 0; i--) {
            // pop indices of days with temperature <= current day
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            // if stack not empty, calculate the distance
            if (!st.empty()) {
                res[i] = st.top() - i;
            }
            // push current index
            st.push(i);
        }
        return res;

    }
};