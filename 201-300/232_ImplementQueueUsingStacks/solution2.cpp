#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> leftStack;
    stack<int> rightStack;

    void flush_left_stack() {
        if (!rightStack.empty())
            return;
        while (!leftStack.empty()) {
            rightStack.push(leftStack.top());
            leftStack.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        leftStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        flush_left_stack();
        int top = rightStack.top();
        rightStack.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        flush_left_stack();
        return rightStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return leftStack.empty() && rightStack.empty();
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

int main()
{
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // returns 1
    cout << queue.pop() << endl;   // returns 1
    cout << queue.empty() << endl; // returns false

    return 0;
}