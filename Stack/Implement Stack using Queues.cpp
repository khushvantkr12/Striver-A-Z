class MyStack {
public:
    queue<int> q;
    MyStack() {}

    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }

    int top() { return q.front(); }

    bool empty() {
        if (q.size() != 0) {
            return false;
        }
        return true;
    }
};