#include <stack>

class MyQueue {
    stack<int> main;
    stack<int> temp;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        while(!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        int popped = temp.top();
        temp.pop();
        while(!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }

        return popped;
    }
    
    int peek() {
        while(!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        int front = temp.top();
        while(!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }

        return front;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
