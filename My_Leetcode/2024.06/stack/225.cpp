#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;  // q1 for store values
    queue<int> q2; // q2 for reverse
    

    MyStack() {

    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);
        }
    }
    
    int pop() {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */