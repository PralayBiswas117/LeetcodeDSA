class MyQueue {
    stack<int> st;
    stack<int> st2;

public:
    MyQueue() {
    }

    void push(int x) {
        st.push(x);
    }

    int pop() {
        while (st.size() > 1) {
            st2.push(st.top());
            st.pop();
        }

        int ans = st.top();
        st.pop();

        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }

        return ans;
    }

    int peek() {
        while (st.size() > 1) {
            st2.push(st.top());
            st.pop();
        }

        int ans = st.top();

        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }

        return ans;
    }

    bool empty() {
        return st.empty();
    }
};