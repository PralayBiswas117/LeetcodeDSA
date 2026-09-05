class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else {
                if (st.empty()) continue;

                int lastOpenIdx = st.top();
                st.pop();

                dp[i + 1] = 2 + dp[i] + dp[lastOpenIdx];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};