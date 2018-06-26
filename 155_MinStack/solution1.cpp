#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> m_stack;
    stack<int> m_min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (m_stack.empty()) {
            m_stack.push(x);
            m_min_stack.push(x);
        } else {
            int top = m_min_stack.top();

            if (top > x)
                m_min_stack.push(x);
            else
                m_min_stack.push(top);

            m_stack.push(x);
        }
    }

    void pop() {
        m_stack.pop();
        m_min_stack.pop();
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;  // it should be -3
    minStack.pop();
    cout << minStack.top() << endl;     // it should be 0
    cout << minStack.getMin() << endl;  // it should be -2

    return 0;
}
