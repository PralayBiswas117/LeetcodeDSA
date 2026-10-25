class MyStack {
private:
    queue<int> a;
    queue<int> b;

public:
    MyStack() {
    }
    
    void push(int x) {
        b.push(x);
        
        
        while (!a.empty()){
            b.push(a.front());
            a.pop();
        }
        swap(a, b);
    }
    
    int pop() {
        int c = a.front();
        a.pop();
        return c;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return a.empty();
    }
};