/*
 * 2020-08-12
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> m_st;
    stack<int> m_min_st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (m_st.empty()) {
            m_st.push(x);
            m_min_st.push(x);
        } else {
            if (m_min_st.top() > x) {
                m_min_st.push(x);
            } else {
                m_min_st.push(m_min_st.top());
            }
            m_st.push(x);
        }
    }

    void pop() {
        m_min_st.pop();
        m_st.pop();
    }

    int top() {
        return m_st.top();
    }

    int getMin() {
        return m_min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl;    // return 0
    cout << minStack.getMin() << endl; // return -2
    return 0;
}
