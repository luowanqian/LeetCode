#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        stack2.pop();

        return top;
    }

    /** Get the front element. */
    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
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